// Supported with union (c) 2018 Union team

#ifndef __ZCCS_CONTEXT_H__VER1__
#define __ZCCS_CONTEXT_H__VER1__

#include "zCCsCutscene.h"
#include "zCCsLib.h"

namespace Gothic_I_Addon {

  class zCCSCutsceneContext : public zCCutscene {
  public:
    zCLASS_DECLARATION( zCCSCutsceneContext )

    enum zTCSPlayResult {
      CS_PLAY_STARTEDPLAYING,
      CS_PLAY_STOPPED,
      CS_PLAY_INTERRUPTED,
      CS_PLAY_RESUMED,
      CS_PLAY_CONTINUED,
      CS_PLAY_DISABLED,
      CS_PLAY_STARTFAILED,
      CS_PLAY_RESUMEFAILED,
      CS_PLAY_TOOFAR,
      CS_PLAY_MAXREACHED,
      CS_PLAY_NOTTRIGGERED,
      CS_PLAY_CHECKFAILED,
      CS_PLAY_MAX
    };

    zTCSPlayResult lastPlayResult;
    int allowedToPlay;
    zCVob* alternativeStageVob;
    int wasTriggered;
    int isCutscene;
    int loaded;
    int reference;
    zCVob* stage;
    zCCSPoolItem* poolItem;
    float lastTimeStamp;
    float lastTimePoint;

    void zCCSCutsceneContext_OnInit()                                   zCall( 0x00405700 );
    void zCCSCutsceneContext_OnInit( zSTRING& )                         zCall( 0x00405790 );
    void zCCSCutsceneContext_OnInit( zCCSBlock*, int, int )             zCall( 0x00406110 );
    zCCSCutsceneContext()                                               zInit( zCCSCutsceneContext_OnInit() );
    zCCSCutsceneContext( zSTRING& a0 )                                  zInit( zCCSCutsceneContext_OnInit( a0 ));
    zCCSCutsceneContext( zCCSBlock* a0, int a1, int a2 )                zInit( zCCSCutsceneContext_OnInit( a0, a1, a2 ));
    void UseThisSubBlock( zCCSBlock* )                                  zCall( 0x004063D0 );
    zSTRING GetCSName() const                                           zCall( 0x00406B20 );
    void HandleTrigger()                                                zCall( 0x00409BB0 );
    void HandleUntrigger()                                              zCall( 0x00409EA0 );
    float GetLastTimePoint()                                            zCall( 0x00409EB0 );
    float GetLastTimeStamp()                                            zCall( 0x00409EC0 );
    zTCSPlayResult GetLastPlayResult( zSTRING& )                        zCall( 0x00409ED0 );
    int AreU( zSTRING const& )                                          zCall( 0x0040A3A0 );
    int AreU( int )                                                     zCall( 0x0040A490 );
    int IsForcedInterrupted()                                           zCall( 0x0040A4B0 );
    int ReplayCutscene()                                                zCall( 0x0040A520 );
    void ForcedResume()                                                 zCall( 0x0040A660 );
    static zCObject* _CreateNewInstance()                               zCall( 0x004055C0 );
    static void operator delete( void*, char const*, char const*, int ) zCall( 0x004056A0 );
    static int DisablePlayCutscenes( int )                              zCall( 0x004056F0 );
    virtual zCClassDef* _GetClassDef() const                            zCall( 0x004056C0 );
    virtual void Archive( zCArchiver& )                                 zCall( 0x004066D0 );
    virtual void Unarchive( zCArchiver& )                               zCall( 0x00406C80 );
    virtual ~zCCSCutsceneContext()                                      zCall( 0x00406480 );
    virtual int IsFinished()                                            zCall( 0x0040A500 );
    virtual int AddMainRole( zCVob* )                                   zCall( 0x0040ACD0 );
    virtual int StartPlaying()                                          zCall( 0x004071A0 );
    virtual void Stop()                                                 zCall( 0x00407880 );
    virtual void Interrupt()                                            zCall( 0x004081A0 );
    virtual int IsCutscene()                                            zCall( 0x004056D0 );
    virtual void PrintDebugInfo( zSTRING const& )                       zCall( 0x0040A6F0 );
    virtual zCVob* GetStage()                                           zCall( 0x0040A5D0 );
    virtual zCVob* CatchPlayer( zCVob* )                                zCall( 0x0040A650 );
    virtual void PrepareBlock()                                         zCall( 0x0040A590 );
    virtual void SetPoolItem( zCCSPoolItem* )                           zCall( 0x0040A530 );
    virtual void SetStage( zCVob* )                                     zCall( 0x0040A5F0 );
    virtual void Play( zCArray<zCEventManager*> const& )                zCall( 0x0040E4B0 );
    virtual void Play( zCArray<zCEventManager*> const&, float, float )  zCall( 0x0040E580 );
    virtual void Play( zCEventManager* )                                zCall( 0x0040E3D0 );
    virtual void Play( zCEventManager*, float, float )                  zCall( 0x0040E420 );
    virtual int Play( zVEC3 )                                           zCall( 0x00408770 );
    virtual void ForcedInterrupt()                                      zCall( 0x00408480 );
    virtual int CheckRoleReactions()                                    zCall( 0x0040A680 );
    virtual int IsPlaying()                                             zCall( 0x0040A4D0 );
    virtual int IsOutputUnit()                                          zCall( 0x004056E0 );

    // compatible with g2 operators style
    zOperatorDelete( zCCSCutsceneContext, zCCutscene )

    // static properties
    static int& playDisabled;
  };

  class zCCSDebugger {
  public:
    zCArray<zCCSBlockBase*> callstack;
    zCCSSyncBlock* callframe;
    zCCSDebugger* deb;

    zCCSDebugger() {}
    virtual ~zCCSDebugger()                               zCall( 0x00420B70 );
    virtual void CSDB_BeginSyncBlock( zCCSSyncBlock* )    zPureCall;
    virtual void CSDB_BeginAtomBlock( zCCSBlockBase* )    zPureCall;
    virtual void CSDB_EndAtomBlock( zCCSBlockBase* )      zPureCall;
    virtual void CSDB_Error( zCCSBlockBase*, zSTRING& )   zPureCall;
    virtual void CSDB_Warning( zCCSBlockBase*, zSTRING& ) zPureCall;
    virtual void CSDB_StartPlaying( zCCutscene* )         zPureCall;
    virtual void CSDB_Stop( zCCutscene* )                 zPureCall;
  };

} // namespace Gothic_I_Addon

#endif // __ZCCS_CONTEXT_H__VER1__