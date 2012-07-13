ADD_SERVICE("buddy/BuddyRelationCache/loader" "BuddyRelationLoader" OceCxxAdapterBuddyRelationReplicaAdapter IceExt ReplicaCluster OceSliceBuddyRelationCache OceSliceBuddyCommon OceSliceReplicaCluster OceSliceSubjectObserver OceSliceXceStorm DbCxxPool OceCommon UtilCxx UtilSlice)
ADD_SERVICE("buddy/BuddyRelationCache/preloader" "BuddyRelationPreloader" ReplicaCluster IceExt OceSliceBuddyRelationCache OceSliceBuddyCommon OceSliceReplicaCluster OceSliceSubjectObserver OceSliceXceStorm DbCxxPool OceCommon UtilCxx UtilSlice)
ADD_SERVICE("buddy/BuddyByApplicantCache/src" "BuddyByApplicantCache"  OceCxxAdapterBuddyByApplicantAdapter ReplicaCluster IceExt OceSliceReplicaCluster OceSliceSubjectObserver  OceSliceXceStorm DbCxxPool OceSliceBuddyByApplicantCache UtilCxx UtilSlice)
ADD_SERVICE("buddy/BuddyByApplicantCache/preloader" "BuddyByApplicantPreloader" ReplicaCluster IceExt OceSliceReplicaCluster OceSliceSubjectObserver  OceSliceXceStorm DbCxxPool OceSliceBuddyByApplicantCache UtilCxx UtilSlice)
ADD_SERVICE("buddy/BuddyByApplicantCache/loader" "BuddyByApplicantLoader"  OceCxxAdapterBuddyByApplicantAdapter ReplicaCluster IceExt OceSliceReplicaCluster OceSliceSubjectObserver  OceSliceXceStorm DbCxxPool OceSliceBuddyByApplicantCache UtilCxx UtilSlice)
ADD_SERVICE("buddy/BuddyByIdCache/cache" "BuddyByIdCache" OceCxxAdapterBuddyByIdReplicaAdapter ReplicaCluster OceSliceBuddyByIdCache OceSliceChecker OceSliceReplicaCluster OceSliceSubjectObserver OceSliceXceStorm IceExt DbCxxPool UtilCxx UtilSlice)
ADD_SERVICE("buddy/BuddyByIdCache/loader" "BuddyByIdLoader" OceCxxAdapterBuddyByIdReplicaAdapter OceCxxAdapterBuddyByNameReplicaAdapter OceCxxAdapterBuddyByAddTimeReplicaAdapter OceCxxAdapterBuddyByOnlineTimeReplicaAdapter OceCxxAdapterStatusCacheAdapter OceCxxAdapterFriendCountCacheReplicaAdapter ReplicaCluster OceSliceBuddyByIdCache OceSliceBuddyByNameCache OceSliceBuddyByAddTimeCache OceSliceBuddyByOnlineTimeCache OceSliceStatusCache OceSliceChecker OceSliceFriendCountCache OceSliceReplicaCluster OceSliceSubjectObserver OceSliceXceStorm DbCxxPool IceExt UtilCxx UtilSlice)
ADD_DC_SERVICE("buddy/BuddyByIdCache/dist" "DistBuddyByIdCacheReloader" OceProto ReplicaCluster ReplicaCluster OceSliceUserApiCache OceSliceReplicaCluster OceSliceSubjectObserver IceExt OceSliceXceStorm DbCxxPool TalkUtil UtilCxx UtilSlice )
ADD_SERVICE("buddy/BuddyFriendsCache/cache" "BuddyFriendsCache" OceCxxAdapterBuddyFriendsAdapter ReplicaCluster OceSliceBuddyFriendsCache OceSliceReplicaCluster OceSliceSubjectObserver OceSliceXceStorm IceExt DbCxxPool UtilCxx UtilSlice)
ADD_SERVICE("buddy/BuddyFriendsCache/reloader" "BuddyFriendsLoader" OceCxxAdapterBuddyFriendsAdapter OceCxxAdapterStatusCacheAdapter ReplicaCluster OceSliceBuddyFriendsCache OceSliceStatusCache OceSliceReplicaCluster OceSliceSubjectObserver OceSliceXceStorm DbCxxPool IceExt UtilCxx UtilSlice)
ADD_SERVICE("buddy/BuddyFriendsCache/preloader" "BuddyFriendsPreloader" OceCxxAdapterBuddyFriendsAdapter ReplicaCluster OceSliceBuddyFriendsCache OceSliceReplicaCluster OceSliceSubjectObserver IceExt OceSliceXceStorm DbCxxPool UtilCxx UtilSlice)
ADD_DC_SERVICE("buddy/BuddyByNameCache/preloader" "BuddyByNamePreloader" OceCxxAdapterBuddyByIdReplicaAdapter OceCxxAdapterUserCacheAdapter OceCxxAdapterDistUserCacheReloaderAdapter OceCxxAdapterBuddyByNameReplicaAdapter ReplicaCluster OceSliceBuddyByIdCache OceSliceBuddyByNameCache OceSliceUserCache OceSliceUserBase OceSliceReplicaCluster OceSliceSubjectObserver IceExt OceSliceXceStorm DbCxxPool UtilCxx UtilSlice)
ADD_DC_SERVICE("buddy/BuddyByNameCache/reloader" "BuddyByNameLoader" OceCxxAdapterBuddyByIdReplicaAdapter OceCxxAdapterUserCacheAdapter OceCxxAdapterDistUserCacheReloaderAdapter OceCxxAdapterBuddyByNameReplicaAdapter ReplicaCluster OceSliceBuddyByIdCache OceSliceBuddyByNameCache OceSliceUserCache OceSliceUserBase OceSliceReplicaCluster OceSliceSubjectObserver IceExt OceSliceXceStorm DbCxxPool UtilCxx UtilSlice)
ADD_SERVICE("buddy/BuddyByNameCache/cache" "BuddyByNameCache" OceCxxAdapterBuddyByNameReplicaAdapter ReplicaCluster OceSliceBuddyByIdCache OceSliceBuddyByNameCache OceSliceChecker OceSliceReplicaCluster OceSliceSubjectObserver OceSliceXceStorm IceExt DbCxxPool UtilCxx UtilSlice)
ADD_SERVICE("buddy/BuddyByAddTimeCache/cache" "BuddyByAddTimeCache" OceCxxAdapterBuddyByAddTimeReplicaAdapter ReplicaCluster OceSliceBuddyByIdCache OceSliceChecker OceSliceBuddyByAddTimeCache OceSliceReplicaCluster OceSliceSubjectObserver OceSliceXceStorm IceExt DbCxxPool UtilCxx UtilSlice)
ADD_SERVICE("buddy/BuddyByAddTimeCache/loader" "BuddyByAddTimeLoader" OceCxxAdapterBuddyByIdReplicaAdapter OceCxxAdapterBuddyByAddTimeReplicaAdapter ReplicaCluster OceSliceBuddyByIdCache OceSliceBuddyByAddTimeCache OceSliceReplicaCluster OceSliceSubjectObserver OceSliceXceStorm DbCxxPool IceExt UtilCxx UtilSlice)
ADD_SERVICE("buddy/BuddyByAddTimeCache/preloader" "BuddyByAddTimePreloader" OceCxxAdapterBuddyByIdReplicaAdapter ReplicaCluster OceSliceBuddyByIdCache OceSliceBuddyByAddTimeCache OceSliceReplicaCluster OceSliceSubjectObserver OceSliceXceStorm DbCxxPool IceExt UtilCxx UtilSlice)
ADD_SERVICE_EXEC("buddy/BuddyByAddTimeCache/test" "BuddyByAddTimeTest" OceCxxAdapterBuddyByAddTimeReplicaAdapter ReplicaCluster OceSliceBuddyByAddTimeCache OceSliceReplicaCluster OceSliceSubjectObserver DbCxxPool IceExt UtilCxx UtilSlice DbCxxPool OceSliceXceStorm )
ADD_SERVICE("buddy/BuddyByOnlineTimeCache/cache" "BuddyByOnlineTimeCache" OceCxxAdapterBuddyByOnlineTimeReplicaAdapter ReplicaCluster OceSliceBuddyByIdCache OceSliceChecker OceSliceBuddyByOnlineTimeCache OceSliceReplicaCluster OceSliceSubjectObserver OceSliceXceStorm IceExt DbCxxPool UtilCxx UtilSlice)
ADD_SERVICE("buddy/BuddyByOnlineTimeCache/loader" "BuddyByOnlineTimeLoader" OceCxxAdapterBuddyByIdReplicaAdapter OceCxxAdapterBuddyByOnlineTimeReplicaAdapter ReplicaCluster OceSliceBuddyByIdCache OceSliceBuddyByOnlineTimeCache OceSliceReplicaCluster OceSliceSubjectObserver OceSliceXceStorm DbCxxPool IceExt UtilCxx UtilSlice)
ADD_SERVICE("buddy/FriendCountCache/src" "FriendCountCache" OceCxxAdapterBuddyByIdReplicaAdapter ReplicaCluster OceSliceBuddyByIdCache OceSliceFriendCountCache OceSlicePresence OceSliceTalkCommon OceSliceReplicaCluster OceSliceSubjectObserver OceSliceXceStorm DbCxxPool IceExt UtilCxx UtilSlice)

ADD_SERVICE("buddy/page/PageFans/cache" "PageFansCache" OceCxxAdapterPageFansReloaderAdapter  ReplicaCluster OceSliceReplicaCluster OceSliceSubjectObserver OceSlice  OceSliceUserBase IceExt OceSliceXceStorm DbCxxPool UtilCxx UtilSlice)

ADD_SERVICE("buddy/page/PageFans/reloader" "PageFansReloader" OceCxxAdapterPageFansCacheAdapter  ReplicaCluster OceSliceReplicaCluster OceSliceSubjectObserver OceSlice  OceSliceUserBase IceExt OceSliceXceStorm DbCxxPool UtilCxx UtilSlice)
ADD_SERVICE("buddy/page/PageFans/preloader" "PageFansPreloader"  ReplicaCluster OceSliceReplicaCluster OceSliceSubjectObserver OceSlice  OceSliceUserBase IceExt OceSliceXceStorm DbCxxPool UtilCxx UtilSlice)

ADD_SERVICE("buddy/BuddyCount/src" "BuddyCount" ReplicaCluster OceSliceReplicaCluster OceSliceSubjectObserver OceSliceBatchUpdater OceSliceBuddyCount IceExt OceSliceXceStorm DbCxxPool UtilCxx UtilSlice)

#ADD_SERVICE("buddy/page/FansPage/cache" "FansPageCache" ReplicaCluster OceSliceFansPage OceSlicePageCommon OceSlicePresence OceSliceTalkCommon OceSliceReplicaCluster OceSliceSubjectObserver OceSliceXceStorm DbCxxPool IceExt UtilCxx UtilSlice)
#ADD_SERVICE("buddy/page/FansPage/reloader" "FansPageReloader" OceCxxAdapterFansPageCacheAdapter ReplicaCluster OceSliceFansPage OceSlicePageCommon OceSliceFriendCountCache OceSlicePresence OceSliceTalkCommon OceSliceReplicaCluster OceSliceSubjectObserver OceSliceXceStorm DbCxxPool IceExt UtilCxx UtilSlice)
#ADD_SERVICE("buddy/page/FansPage/preloader" "FansPagePreloader" OceCxxAdapterFansPageCacheAdapter ReplicaCluster OceSliceFansPage OceSlicePageCommon OceSliceFriendCountCache OceSlicePresence OceSliceTalkCommon OceSliceReplicaCluster OceSliceSubjectObserver OceSliceXceStorm DbCxxPool IceExt UtilCxx UtilSlice)



#ADD_SERVICE_EXEC("buddy/page/PageCommonFans/cache/src" "PageCommonFansCache" Base OceCxxAdapterFriendRankCacheAdapter OceSliceFriendRank OceCxxAdapterBuddyByIdReplicaAdapter OceSliceBuddyCore OceSliceBuddyByIdCache ReplicaCluster  OceSliceReplicaCluster OceSliceSubjectObserver OceSliceXceStorm IceExt UtilCxx UtilSlice DbCxxPool OceSlice libprotobuf.so libboost_system-gcc41-mt-1_38.so)

ADD_SERVICE("buddy/page/PageCommonFans/cache/src" "PageCommonFansCache" Base OceCxxAdapterFriendRankCacheAdapter OceSliceFriendRank OceCxxAdapterBuddyByIdReplicaAdapter OceSliceBuddyCore OceSliceBuddyByIdCache ReplicaCluster  OceSliceReplicaCluster OceSliceSubjectObserver OceSliceXceStorm IceExt UtilCxx UtilSlice DbCxxPool OceSlice libprotobuf.so libboost_system-gcc41-mt-1_38.so)



