import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

/**
 * 此FeedBuilder用于构建发送stype为xxx，数据版本为x的新鲜事
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
        _flag.put("<?cs var:item.name ?>" , false);
    <?cs /each ?>

    <?cs each:item = FeedStruct.loop ?>
        _flag.put("<?cs var:item.name ?>" , false);
    <?cs /each ?>

  }

  <?cs each:item = FeedStruct.keys ?>
  public void SetKey_<?cs var:name(item) ?>(<?cs if:item.type == number ?> long <?cs else ?> String <?cs /if ?> <?cs var:name(item) ?>){
    _data.put("<?cs var:item.name ?>", String.valueOf( <?cs var:name(item) ?> ) );
    _flag.put("<?cs var:item.name ?>",true);
  }
  <?cs /each ?>

  <?cs each:item = FeedStruct.loop ?>
  public void AddRepeat_<?cs var:name(item) ?>(
    <?cs if:item.type == "node" ?>
      <?cs set:i = #0 ?>
      <?cs each:it = item ?>
        <?cs if:subcount(it) > 1 ?>
          <?cs if:i ?>,<?cs else ?><?cs set:i = #1 ?><?cs /if ?> <?cs if:it.type == number ?> long <?cs else ?> String <?cs /if ?>  <?cs var:name(it) ?>
        <?cs /if ?>
      <?cs /each ?>
    <?cs else ?>
      <?cs if:item.type == number ?> long <?cs else ?> String <?cs /if ?> <?cs var:name(item.name) ?>
    <?cs /if ?>
  ){
      int count = <?cs var:name(item) ?>_list.size();
      Map<String,String> obj = new HashMap<String,String>();
     <?cs if:item.type == "node" ?>
      <?cs each:it = item ?>
        <?cs if:subcount(it) > 1 ?>
          obj.put("<?cs var:item.name ?>."+String.valueOf(count)+".<?cs var:it.name ?>", String.valueOf(<?cs var:name(it) ?> ));      
        <?cs /if ?>
      <?cs /each ?>
     <?cs else ?>
      obj.put("<?cs var:item.name ?>."+ String.valueOf(count),String.valueOf(<?cs var:name(item) ?>));
     <?cs /if ?>
     <?cs var:name(item) ?>_list.add(obj);
     _flag.put("<?cs var:item.name ?>",true);
  }
  <?cs /each ?>
  

  <?cs if:FeedStruct.loop ?>
  void MergeData(){
    <?cs each:item = FeedStruct.loop ?>
      for(int i = 0; i < <?cs var:name(item) ?>_list.size(); ++i){
        _data.putAll(<?cs var:name(item) ?>_list.at(i));
      }
    <?cs /each ?>
  }
  <?cs /if ?>
  public void DispatchFeed(){
    System.out.println(_data.toString());
  }
}
