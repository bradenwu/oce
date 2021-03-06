import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.Iterator;
import java.util.regex.Matcher;
import java.util.regex.Pattern;
import MyUtil.MceException;

import xce.feed.FeedTypeConfigNotFoundException;
import xce.feed.NotAllowedToSendException;
import xce.feed.FeedReply;
/**
 * 此FeedBuilder_<?cs var:FeedStruct.stype  ?>_<?cs var:FeedStruct.version ?>用于构建发送stype为<?cs var:FeedStruct.stype  ?>，数据版本为<?cs var:FeedStruct.version ?>的新鲜事
 * 新鲜事说明：<?cs var:FeedStruct.comment ?>
 * @author antonio
 *
 */

class FeedBuilder_<?cs var:FeedStruct.stype  ?>_<?cs var:FeedStruct.version ?> {
	/**新鲜事的类型*/
	public final static int stype = <?cs var:FeedStruct.stype  ?>;
	/**新鲜事的版本号*/
	public final static int version = <?cs var:FeedStruct.version ?>;

	
  <?cs each:item = FeedStruct.loop ?>
    private List< Map<String,String> > <?cs var:name(item) ?>_list = new ArrayList< Map<String,String> >();
  <?cs /each ?>
  private Map<String,String> _data = new HashMap<String,String>();
  private Map<String,Boolean> _flag = new HashMap<String, Boolean>();
  public FeedBuilder_<?cs var:FeedStruct.stype  ?>_<?cs var:FeedStruct.version ?> () {
    <?cs each:item = FeedStruct.keys ?>
        _flag.put("<?cs var:item.name ?>" , <?cs var:item.optional ?>);<?cs /each ?>

    <?cs each:item = FeedStruct.loop ?>
        _flag.put("<?cs var:item.name ?>" , <?cs var:item.optional ?>);<?cs /each ?>

    <?cs if:FeedStruct.is_custom_expr == "true" ?>
	_flag.put("expr",false);
    <?cs /if ?>
  }

  boolean CheckUrl(String url) {
	  if(url.isEmpty()){
		return true;
	  }
	  Pattern p = Pattern
		  .compile("^http://[^#]+$");
	  Matcher m = p.matcher(url);
	  if (m.find()) {
		  return true;
	  }
	  System.err.println("URL格式不正确 url:"+url);
	  return false;
  }

   <?cs if:FeedStruct.is_custom_expr == "true" ?>
   public boolean AddExpr(String expr) {
		Pattern p = Pattern
				.compile("^[ufaApsvgzx]{1}\\([1-9]+[0-9]*\\)([\\+\\-\\&]{1}[ufaApsvgzx]{1}\\([1-9]+[0-9]*\\))*$");
		Matcher m = p.matcher(expr);
		if (m.find()) {
			_data.put("expr", expr);
			_flag.put("expr", true);
			return true;
		}
		System.err.println("分发表达式 expr="+expr+",设置的值无效");
		return false;
   }
   <?cs /if ?>

  <?cs each:item = FeedStruct.keys ?>
  /**
   *@param <?cs var:name(item) ?> comment:<?cs var:item.comment ?>
   */
  public void SetKey_<?cs var:name(item) ?>(<?cs if:item.type == "number" ?> long <?cs else ?> String <?cs /if ?> <?cs var:name(item) ?>){
    <?cs if:item.type == "link" ?>
    if(!CheckUrl(<?cs var:name(item) ?> )){
    	_flag.put("<?cs var:item.name ?>",false);
    	return;
    }
    <?cs /if ?>
    _data.put("<?cs var:item.name ?>", String.valueOf( <?cs var:name(item) ?> ) );
    _flag.put("<?cs var:item.name ?>",true);
  }
  <?cs /each ?>

  <?cs each:item = FeedStruct.loop ?>
  /**
   *@param <?cs var:name(item) ?> comment:<?cs var:item.comment ?>
   */
  public void AddRepeat_<?cs var:name(item) ?>(
    <?cs if:item.type == "node" ?>
	<?cs set:i = #0 ?>
	<?cs each:it = item ?>
		<?cs if:subcount(it) > 1 ?>
          		<?cs if:i ?>,<?cs else ?><?cs set:i = #1 ?>
			<?cs /if ?> 
			<?cs if:it.type == "number" ?> long <?cs else ?> String 
			<?cs /if ?>  
			<?cs var:name(it) ?>
		<?cs /if ?>
	<?cs /each ?>
    <?cs else ?>
	<?cs if:item.type == "number" ?> long <?cs else ?> String 
	<?cs /if ?> 
	<?cs var:name(item) ?>
    <?cs /if ?>
  ){
    _flag.put("<?cs var:item.name ?>",false);
    <?cs if:item.type == "node" ?>
        <?cs each:it = item ?>
                <?cs if:subcount(it) > 1 ?>
                        <?cs if:it.type == "link" ?> if(!CheckUrl(<?cs var:name(it) ?>)){return;}
                        <?cs /if ?>
                <?cs /if ?>
        <?cs /each ?>
    <?cs else ?>
        <?cs if:item.type == "link" ?> if(!CheckUrl(<?cs var:name(item) ?>)){return;}
        <?cs /if ?>
    <?cs /if ?>     



      int count = <?cs var:name(item) ?>_list.size();
      Map<String,String> obj = new HashMap<String,String>();
     <?cs if:item.type == "node" ?>
      <?cs each:it = item ?><?cs if:subcount(it) > 1 ?>
          obj.put("<?cs var:item.name ?>."+String.valueOf(count)+".<?cs var:it.name ?>", String.valueOf(<?cs var:name(it) ?> ));<?cs /if ?><?cs /each ?>
     <?cs else ?>
      obj.put("<?cs var:item.name ?>."+ String.valueOf(count),String.valueOf(<?cs var:name(item) ?>));<?cs /if ?>
      <?cs var:name(item) ?>_list.add(obj);
     _flag.put("<?cs var:item.name ?>",true);
  }
  <?cs /each ?>
  

  <?cs if:subcount(FeedStruct.loop) ?>
  void MergeData(){
    <?cs each:item = FeedStruct.loop ?>
      for(int i = 0; i < <?cs var:name(item) ?>_list.size(); ++i){
        _data.putAll(<?cs var:name(item) ?>_list.get(i));
      }
    <?cs /each ?>
  }
  <?cs /if ?>
	  /**
	   *调用此方法触发产生新鲜事，用于产生带回复的新鲜事，所以需要传FeedReply参数
	   */
	  public void DispatchFeed(FeedReply reply) {
		  StringBuffer buf = new StringBuffer();

		  Iterator it = _flag.entrySet().iterator();
		  while(it.hasNext()){
			  Map.Entry<String, Boolean> entry = (Map.Entry<String, Boolean>)it.next(); 
			  if(!entry.getValue()){
				  if(buf.length() == 0){
					  buf.append("Any SetKey function not set, include keys:").append(entry.getKey());
				  }else{
					  buf.append(",").append(entry.getKey());
				  }

			  }
		  }
		  if(buf.length() > 0){
			  System.err.println(buf.toString());
			  return;
		  }
  	<?cs if:subcount(FeedStruct.loop) ?>
		MergeData();
	<?cs /if ?>
		  try {
			if(reply == null){
			  FeedCreatorAdapter.getInstance().Create(stype, version, _data);
			}else{
			  FeedCreatorAdapter.getInstance().CreateWithReply(stype, version, _data, reply);
			}

		  } catch (FeedTypeConfigNotFoundException e) {
			  e.printStackTrace();
		  } catch (NotAllowedToSendException e) {
			  // TODO Auto-generated catch block
			  e.printStackTrace();
		  } catch (MceException e) {
			  // TODO Auto-generated catch block
			  e.printStackTrace();
		  }
	  }
	/**
	* 调用此方法触发产生新鲜事
	*/
	public void DispatchFeed(){
		DispatchFeed(null);
	}
}
