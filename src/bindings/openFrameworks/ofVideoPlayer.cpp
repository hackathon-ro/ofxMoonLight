/**
 *
 * MACHINE GENERATED FILE. DO NOT EDIT.
 *
 * Bindings for class ofVideoPlayer
 *
 * This file has been generated by dub 2.1.~.
 */
#include "dub/dub.h"
#include "api/openFrameworks/video/ofVideoPlayer.h"


/** ~ofVideoPlayer()
 * 
 */
static int ofVideoPlayer__ofVideoPlayer(lua_State *L) {
  try {
    DubUserdata *userdata = ((DubUserdata*)dub_checksdata_d(L, 1, "ofVideoPlayer"));
    if (userdata->gc) {
      ofVideoPlayer *self = (ofVideoPlayer *)userdata->ptr;
      delete self;
    }
    userdata->gc = false;
    return 0;
  } catch (std::exception &e) {
    lua_pushfstring(L, "__gc: %s", e.what());
  } catch (...) {
    lua_pushfstring(L, "__gc: Unknown exception");
  }
  return dub_error(L);
}

/** Set attributes (key, value)
 * 
 */
static int ofVideoPlayer__set_(lua_State *L) {

  ofVideoPlayer *self = *((ofVideoPlayer **)dub_checksdata_n(L, 1, "ofVideoPlayer"));
  const char *key = luaL_checkstring(L, 2);
  int key_h = dub_hash(key, 2);
  switch(key_h) {
    case 1: {
      if (DUB_ASSERT_KEY(key, "height")) break;
      self->height = luaL_checkint(L, 3);
      return 0;
    }
    case 0: {
      if (DUB_ASSERT_KEY(key, "width")) break;
      self->width = luaL_checkint(L, 3);
      return 0;
    }
  }
  if (lua_istable(L, 1)) {
    lua_rawset(L, 1);
  } else {
    luaL_error(L, KEY_EXCEPTION_MSG, key);
  }
  return 0;
}

/** Get attributes (key)
 * 
 */
static int ofVideoPlayer__get_(lua_State *L) {

  ofVideoPlayer *self = *((ofVideoPlayer **)dub_checksdata_n(L, 1, "ofVideoPlayer", true));
  const char *key = luaL_checkstring(L, 2);
  // <self> "key" <mt>
  // rawget(mt, key)
  lua_pushvalue(L, 2);
  // <self> "key" <mt> "key"
  lua_rawget(L, -2);
  if (!lua_isnil(L, -1)) {
    // Found method.
    return 1;
  } else {
    // Not in mt = attribute access.
    lua_pop(L, 2);
  }
  int key_h = dub_hash(key, 2);
  switch(key_h) {
    case 1: {
      if (DUB_ASSERT_KEY(key, "height")) break;
      lua_pushnumber(L, self->height);
      return 1;
    }
    case 0: {
      if (DUB_ASSERT_KEY(key, "width")) break;
      lua_pushnumber(L, self->width);
      return 1;
    }
  }
  return 0;
}

/** Cast (class_name)
 * 
 */
static int ofVideoPlayer__cast_(lua_State *L) {

  ofVideoPlayer *self = *((ofVideoPlayer **)dub_checksdata_n(L, 1, "ofVideoPlayer"));
  const char *key = luaL_checkstring(L, 2);
  void **retval__ = (void**)lua_newuserdata(L, sizeof(void*));
  int key_h = dub_hash(key, 6);
  switch(key_h) {
    case 2: {
      if (DUB_ASSERT_KEY(key, "ofBaseVideoPlayer")) break;
      *retval__ = static_cast<ofBaseVideoPlayer *>(self);
      return 1;
    }
    case 5: {
      if (DUB_ASSERT_KEY(key, "ofBaseVideo")) break;
      *retval__ = static_cast<ofBaseVideo *>(self);
      return 1;
    }
    case 0: {
      if (DUB_ASSERT_KEY(key, "ofBaseUpdates")) break;
      *retval__ = static_cast<ofBaseUpdates *>(self);
      return 1;
    }
    case 4: {
      if (DUB_ASSERT_KEY(key, "ofBaseVideoDraws")) break;
      *retval__ = static_cast<ofBaseVideoDraws *>(self);
      return 1;
    }
  }
  return 0;
}

/** ofVideoPlayer::ofVideoPlayer()
 * api/openFrameworks/video/ofVideoPlayer.h:13
 */
static int ofVideoPlayer_ofVideoPlayer(lua_State *L) {
  try {
    ofVideoPlayer *retval__ = new ofVideoPlayer();
    dub_pushudata(L, retval__, "ofVideoPlayer", true);
    return 1;
  } catch (std::exception &e) {
    lua_pushfstring(L, "new: %s", e.what());
  } catch (...) {
    lua_pushfstring(L, "new: Unknown exception");
  }
  return dub_error(L);
}

/** void ofVideoPlayer::setPlayer(ofPtr< ofBaseVideoPlayer > newPlayer)
 * api/openFrameworks/video/ofVideoPlayer.h:15
 */
static int ofVideoPlayer_setPlayer(lua_State *L) {
  try {
    ofVideoPlayer *self = *((ofVideoPlayer **)dub_checksdata(L, 1, "ofVideoPlayer"));
    ofPtr < ofBaseVideoPlayer > *newPlayer = *((ofPtr < ofBaseVideoPlayer > **)dub_checksdata(L, 2, "ofPtr < ofBaseVideoPlayer >"));
    self->setPlayer(*newPlayer);
    return 0;
  } catch (std::exception &e) {
    lua_pushfstring(L, "setPlayer: %s", e.what());
  } catch (...) {
    lua_pushfstring(L, "setPlayer: Unknown exception");
  }
  return dub_error(L);
}

/** ofPtr<ofBaseVideoPlayer> ofVideoPlayer::getPlayer()
 * api/openFrameworks/video/ofVideoPlayer.h:16
 */
static int ofVideoPlayer_getPlayer(lua_State *L) {
  try {
    ofVideoPlayer *self = *((ofVideoPlayer **)dub_checksdata(L, 1, "ofVideoPlayer"));
    dub_pushudata(L, new ofPtr < ofBaseVideoPlayer >(self->getPlayer()), "ofPtr < ofBaseVideoPlayer >", true);
    return 1;
  } catch (std::exception &e) {
    lua_pushfstring(L, "getPlayer: %s", e.what());
  } catch (...) {
    lua_pushfstring(L, "getPlayer: Unknown exception");
  }
  return dub_error(L);
}

/** bool ofVideoPlayer::loadMovie(string name)
 * api/openFrameworks/video/ofVideoPlayer.h:18
 */
static int ofVideoPlayer_loadMovie(lua_State *L) {
  try {
    ofVideoPlayer *self = *((ofVideoPlayer **)dub_checksdata(L, 1, "ofVideoPlayer"));
    string *name = *((string **)dub_checksdata(L, 2, "string"));
    lua_pushboolean(L, self->loadMovie(*name));
    return 1;
  } catch (std::exception &e) {
    lua_pushfstring(L, "loadMovie: %s", e.what());
  } catch (...) {
    lua_pushfstring(L, "loadMovie: Unknown exception");
  }
  return dub_error(L);
}

/** string ofVideoPlayer::getMoviePath()
 * api/openFrameworks/video/ofVideoPlayer.h:19
 */
static int ofVideoPlayer_getMoviePath(lua_State *L) {
  try {
    ofVideoPlayer *self = *((ofVideoPlayer **)dub_checksdata(L, 1, "ofVideoPlayer"));
    dub_pushudata(L, new string(self->getMoviePath()), "string", true);
    return 1;
  } catch (std::exception &e) {
    lua_pushfstring(L, "getMoviePath: %s", e.what());
  } catch (...) {
    lua_pushfstring(L, "getMoviePath: Unknown exception");
  }
  return dub_error(L);
}

/** bool ofVideoPlayer::setPixelFormat(ofPixelFormat pixelFormat)
 * api/openFrameworks/video/ofVideoPlayer.h:21
 */
static int ofVideoPlayer_setPixelFormat(lua_State *L) {
  try {
    ofVideoPlayer *self = *((ofVideoPlayer **)dub_checksdata(L, 1, "ofVideoPlayer"));
    ofPixelFormat pixelFormat = (ofPixelFormat)dub_checkint(L, 2);
    lua_pushboolean(L, self->setPixelFormat(pixelFormat));
    return 1;
  } catch (std::exception &e) {
    lua_pushfstring(L, "setPixelFormat: %s", e.what());
  } catch (...) {
    lua_pushfstring(L, "setPixelFormat: Unknown exception");
  }
  return dub_error(L);
}

/** ofPixelFormat ofVideoPlayer::getPixelFormat()
 * api/openFrameworks/video/ofVideoPlayer.h:22
 */
static int ofVideoPlayer_getPixelFormat(lua_State *L) {
  try {
    ofVideoPlayer *self = *((ofVideoPlayer **)dub_checksdata(L, 1, "ofVideoPlayer"));
    lua_pushnumber(L, self->getPixelFormat());
    return 1;
  } catch (std::exception &e) {
    lua_pushfstring(L, "getPixelFormat: %s", e.what());
  } catch (...) {
    lua_pushfstring(L, "getPixelFormat: Unknown exception");
  }
  return dub_error(L);
}

/** void ofVideoPlayer::closeMovie()
 * api/openFrameworks/video/ofVideoPlayer.h:24
 */
static int ofVideoPlayer_closeMovie(lua_State *L) {
  try {
    ofVideoPlayer *self = *((ofVideoPlayer **)dub_checksdata(L, 1, "ofVideoPlayer"));
    self->closeMovie();
    return 0;
  } catch (std::exception &e) {
    lua_pushfstring(L, "closeMovie: %s", e.what());
  } catch (...) {
    lua_pushfstring(L, "closeMovie: Unknown exception");
  }
  return dub_error(L);
}

/** void ofVideoPlayer::close()
 * api/openFrameworks/video/ofVideoPlayer.h:25
 */
static int ofVideoPlayer_close(lua_State *L) {
  try {
    ofVideoPlayer *self = *((ofVideoPlayer **)dub_checksdata(L, 1, "ofVideoPlayer"));
    self->close();
    return 0;
  } catch (std::exception &e) {
    lua_pushfstring(L, "close: %s", e.what());
  } catch (...) {
    lua_pushfstring(L, "close: Unknown exception");
  }
  return dub_error(L);
}

/** void ofVideoPlayer::update()
 * api/openFrameworks/video/ofVideoPlayer.h:27
 */
static int ofVideoPlayer_update(lua_State *L) {
  try {
    ofVideoPlayer *self = *((ofVideoPlayer **)dub_checksdata(L, 1, "ofVideoPlayer"));
    self->update();
    return 0;
  } catch (std::exception &e) {
    lua_pushfstring(L, "update: %s", e.what());
  } catch (...) {
    lua_pushfstring(L, "update: Unknown exception");
  }
  return dub_error(L);
}

/** void ofVideoPlayer::play()
 * api/openFrameworks/video/ofVideoPlayer.h:29
 */
static int ofVideoPlayer_play(lua_State *L) {
  try {
    ofVideoPlayer *self = *((ofVideoPlayer **)dub_checksdata(L, 1, "ofVideoPlayer"));
    self->play();
    return 0;
  } catch (std::exception &e) {
    lua_pushfstring(L, "play: %s", e.what());
  } catch (...) {
    lua_pushfstring(L, "play: Unknown exception");
  }
  return dub_error(L);
}

/** void ofVideoPlayer::stop()
 * api/openFrameworks/video/ofVideoPlayer.h:30
 */
static int ofVideoPlayer_stop(lua_State *L) {
  try {
    ofVideoPlayer *self = *((ofVideoPlayer **)dub_checksdata(L, 1, "ofVideoPlayer"));
    self->stop();
    return 0;
  } catch (std::exception &e) {
    lua_pushfstring(L, "stop: %s", e.what());
  } catch (...) {
    lua_pushfstring(L, "stop: Unknown exception");
  }
  return dub_error(L);
}

/** bool ofVideoPlayer::isFrameNew()
 * api/openFrameworks/video/ofVideoPlayer.h:32
 */
static int ofVideoPlayer_isFrameNew(lua_State *L) {
  try {
    ofVideoPlayer *self = *((ofVideoPlayer **)dub_checksdata(L, 1, "ofVideoPlayer"));
    lua_pushboolean(L, self->isFrameNew());
    return 1;
  } catch (std::exception &e) {
    lua_pushfstring(L, "isFrameNew: %s", e.what());
  } catch (...) {
    lua_pushfstring(L, "isFrameNew: Unknown exception");
  }
  return dub_error(L);
}

/** float ofVideoPlayer::getPosition()
 * api/openFrameworks/video/ofVideoPlayer.h:35
 */
static int ofVideoPlayer_getPosition(lua_State *L) {
  try {
    ofVideoPlayer *self = *((ofVideoPlayer **)dub_checksdata(L, 1, "ofVideoPlayer"));
    lua_pushnumber(L, self->getPosition());
    return 1;
  } catch (std::exception &e) {
    lua_pushfstring(L, "getPosition: %s", e.what());
  } catch (...) {
    lua_pushfstring(L, "getPosition: Unknown exception");
  }
  return dub_error(L);
}

/** float ofVideoPlayer::getSpeed()
 * api/openFrameworks/video/ofVideoPlayer.h:36
 */
static int ofVideoPlayer_getSpeed(lua_State *L) {
  try {
    ofVideoPlayer *self = *((ofVideoPlayer **)dub_checksdata(L, 1, "ofVideoPlayer"));
    lua_pushnumber(L, self->getSpeed());
    return 1;
  } catch (std::exception &e) {
    lua_pushfstring(L, "getSpeed: %s", e.what());
  } catch (...) {
    lua_pushfstring(L, "getSpeed: Unknown exception");
  }
  return dub_error(L);
}

/** float ofVideoPlayer::getDuration()
 * api/openFrameworks/video/ofVideoPlayer.h:37
 */
static int ofVideoPlayer_getDuration(lua_State *L) {
  try {
    ofVideoPlayer *self = *((ofVideoPlayer **)dub_checksdata(L, 1, "ofVideoPlayer"));
    lua_pushnumber(L, self->getDuration());
    return 1;
  } catch (std::exception &e) {
    lua_pushfstring(L, "getDuration: %s", e.what());
  } catch (...) {
    lua_pushfstring(L, "getDuration: Unknown exception");
  }
  return dub_error(L);
}

/** bool ofVideoPlayer::getIsMovieDone()
 * api/openFrameworks/video/ofVideoPlayer.h:38
 */
static int ofVideoPlayer_getIsMovieDone(lua_State *L) {
  try {
    ofVideoPlayer *self = *((ofVideoPlayer **)dub_checksdata(L, 1, "ofVideoPlayer"));
    lua_pushboolean(L, self->getIsMovieDone());
    return 1;
  } catch (std::exception &e) {
    lua_pushfstring(L, "getIsMovieDone: %s", e.what());
  } catch (...) {
    lua_pushfstring(L, "getIsMovieDone: Unknown exception");
  }
  return dub_error(L);
}

/** void ofVideoPlayer::setPosition(float pct)
 * api/openFrameworks/video/ofVideoPlayer.h:40
 */
static int ofVideoPlayer_setPosition(lua_State *L) {
  try {
    ofVideoPlayer *self = *((ofVideoPlayer **)dub_checksdata(L, 1, "ofVideoPlayer"));
    float pct = dub_checknumber(L, 2);
    self->setPosition(pct);
    return 0;
  } catch (std::exception &e) {
    lua_pushfstring(L, "setPosition: %s", e.what());
  } catch (...) {
    lua_pushfstring(L, "setPosition: Unknown exception");
  }
  return dub_error(L);
}

/** void ofVideoPlayer::setVolume(float volume)
 * api/openFrameworks/video/ofVideoPlayer.h:41
 */
static int ofVideoPlayer_setVolume(lua_State *L) {
  try {
    ofVideoPlayer *self = *((ofVideoPlayer **)dub_checksdata(L, 1, "ofVideoPlayer"));
    float volume = dub_checknumber(L, 2);
    self->setVolume(volume);
    return 0;
  } catch (std::exception &e) {
    lua_pushfstring(L, "setVolume: %s", e.what());
  } catch (...) {
    lua_pushfstring(L, "setVolume: Unknown exception");
  }
  return dub_error(L);
}

/** void ofVideoPlayer::setLoopState(ofLoopType state)
 * api/openFrameworks/video/ofVideoPlayer.h:42
 */
static int ofVideoPlayer_setLoopState(lua_State *L) {
  try {
    ofVideoPlayer *self = *((ofVideoPlayer **)dub_checksdata(L, 1, "ofVideoPlayer"));
    ofLoopType state = (ofLoopType)dub_checkint(L, 2);
    self->setLoopState(state);
    return 0;
  } catch (std::exception &e) {
    lua_pushfstring(L, "setLoopState: %s", e.what());
  } catch (...) {
    lua_pushfstring(L, "setLoopState: Unknown exception");
  }
  return dub_error(L);
}

/** ofLoopType ofVideoPlayer::getLoopState()
 * api/openFrameworks/video/ofVideoPlayer.h:43
 */
static int ofVideoPlayer_getLoopState(lua_State *L) {
  try {
    ofVideoPlayer *self = *((ofVideoPlayer **)dub_checksdata(L, 1, "ofVideoPlayer"));
    lua_pushnumber(L, self->getLoopState());
    return 1;
  } catch (std::exception &e) {
    lua_pushfstring(L, "getLoopState: %s", e.what());
  } catch (...) {
    lua_pushfstring(L, "getLoopState: Unknown exception");
  }
  return dub_error(L);
}

/** void ofVideoPlayer::setSpeed(float speed)
 * api/openFrameworks/video/ofVideoPlayer.h:44
 */
static int ofVideoPlayer_setSpeed(lua_State *L) {
  try {
    ofVideoPlayer *self = *((ofVideoPlayer **)dub_checksdata(L, 1, "ofVideoPlayer"));
    float speed = dub_checknumber(L, 2);
    self->setSpeed(speed);
    return 0;
  } catch (std::exception &e) {
    lua_pushfstring(L, "setSpeed: %s", e.what());
  } catch (...) {
    lua_pushfstring(L, "setSpeed: Unknown exception");
  }
  return dub_error(L);
}

/** void ofVideoPlayer::setFrame(int frame)
 * api/openFrameworks/video/ofVideoPlayer.h:45
 */
static int ofVideoPlayer_setFrame(lua_State *L) {
  try {
    ofVideoPlayer *self = *((ofVideoPlayer **)dub_checksdata(L, 1, "ofVideoPlayer"));
    int frame = dub_checkint(L, 2);
    self->setFrame(frame);
    return 0;
  } catch (std::exception &e) {
    lua_pushfstring(L, "setFrame: %s", e.what());
  } catch (...) {
    lua_pushfstring(L, "setFrame: Unknown exception");
  }
  return dub_error(L);
}

/** void ofVideoPlayer::setUseTexture(bool bUse)
 * api/openFrameworks/video/ofVideoPlayer.h:47
 */
static int ofVideoPlayer_setUseTexture(lua_State *L) {
  try {
    ofVideoPlayer *self = *((ofVideoPlayer **)dub_checksdata(L, 1, "ofVideoPlayer"));
    bool bUse = dub_checkboolean(L, 2);
    self->setUseTexture(bUse);
    return 0;
  } catch (std::exception &e) {
    lua_pushfstring(L, "setUseTexture: %s", e.what());
  } catch (...) {
    lua_pushfstring(L, "setUseTexture: Unknown exception");
  }
  return dub_error(L);
}

/** ofTexture& ofVideoPlayer::getTextureReference()
 * api/openFrameworks/video/ofVideoPlayer.h:48
 */
static int ofVideoPlayer_getTextureReference(lua_State *L) {
  try {
    ofVideoPlayer *self = *((ofVideoPlayer **)dub_checksdata(L, 1, "ofVideoPlayer"));
    dub_pushudata(L, &self->getTextureReference(), "ofTexture", false);
    return 1;
  } catch (std::exception &e) {
    lua_pushfstring(L, "getTextureReference: %s", e.what());
  } catch (...) {
    lua_pushfstring(L, "getTextureReference: Unknown exception");
  }
  return dub_error(L);
}

/** void ofVideoPlayer::draw(float x, float y, float w, float h)
 * api/openFrameworks/video/ofVideoPlayer.h:49
 */
static int ofVideoPlayer_draw(lua_State *L) {
  try {
    ofVideoPlayer *self = *((ofVideoPlayer **)dub_checksdata(L, 1, "ofVideoPlayer"));
    int top__ = lua_gettop(L);
    if (top__ >= 5) {
      float x = dub_checknumber(L, 2);
      float y = dub_checknumber(L, 3);
      float w = dub_checknumber(L, 4);
      float h = dub_checknumber(L, 5);
      self->draw(x, y, w, h);
      return 0;
    } else {
      float x = dub_checknumber(L, 2);
      float y = dub_checknumber(L, 3);
      self->draw(x, y);
      return 0;
    }
  } catch (std::exception &e) {
    lua_pushfstring(L, "draw: %s", e.what());
  } catch (...) {
    lua_pushfstring(L, "draw: Unknown exception");
  }
  return dub_error(L);
}

/** void ofVideoPlayer::setAnchorPercent(float xPct, float yPct)
 * api/openFrameworks/video/ofVideoPlayer.h:55
 */
static int ofVideoPlayer_setAnchorPercent(lua_State *L) {
  try {
    ofVideoPlayer *self = *((ofVideoPlayer **)dub_checksdata(L, 1, "ofVideoPlayer"));
    float xPct = dub_checknumber(L, 2);
    float yPct = dub_checknumber(L, 3);
    self->setAnchorPercent(xPct, yPct);
    return 0;
  } catch (std::exception &e) {
    lua_pushfstring(L, "setAnchorPercent: %s", e.what());
  } catch (...) {
    lua_pushfstring(L, "setAnchorPercent: Unknown exception");
  }
  return dub_error(L);
}

/** void ofVideoPlayer::setAnchorPoint(float x, float y)
 * api/openFrameworks/video/ofVideoPlayer.h:56
 */
static int ofVideoPlayer_setAnchorPoint(lua_State *L) {
  try {
    ofVideoPlayer *self = *((ofVideoPlayer **)dub_checksdata(L, 1, "ofVideoPlayer"));
    float x = dub_checknumber(L, 2);
    float y = dub_checknumber(L, 3);
    self->setAnchorPoint(x, y);
    return 0;
  } catch (std::exception &e) {
    lua_pushfstring(L, "setAnchorPoint: %s", e.what());
  } catch (...) {
    lua_pushfstring(L, "setAnchorPoint: Unknown exception");
  }
  return dub_error(L);
}

/** void ofVideoPlayer::resetAnchor()
 * api/openFrameworks/video/ofVideoPlayer.h:57
 */
static int ofVideoPlayer_resetAnchor(lua_State *L) {
  try {
    ofVideoPlayer *self = *((ofVideoPlayer **)dub_checksdata(L, 1, "ofVideoPlayer"));
    self->resetAnchor();
    return 0;
  } catch (std::exception &e) {
    lua_pushfstring(L, "resetAnchor: %s", e.what());
  } catch (...) {
    lua_pushfstring(L, "resetAnchor: Unknown exception");
  }
  return dub_error(L);
}

/** void ofVideoPlayer::setPaused(bool bPause)
 * api/openFrameworks/video/ofVideoPlayer.h:59
 */
static int ofVideoPlayer_setPaused(lua_State *L) {
  try {
    ofVideoPlayer *self = *((ofVideoPlayer **)dub_checksdata(L, 1, "ofVideoPlayer"));
    bool bPause = dub_checkboolean(L, 2);
    self->setPaused(bPause);
    return 0;
  } catch (std::exception &e) {
    lua_pushfstring(L, "setPaused: %s", e.what());
  } catch (...) {
    lua_pushfstring(L, "setPaused: Unknown exception");
  }
  return dub_error(L);
}

/** int ofVideoPlayer::getCurrentFrame()
 * api/openFrameworks/video/ofVideoPlayer.h:61
 */
static int ofVideoPlayer_getCurrentFrame(lua_State *L) {
  try {
    ofVideoPlayer *self = *((ofVideoPlayer **)dub_checksdata(L, 1, "ofVideoPlayer"));
    lua_pushnumber(L, self->getCurrentFrame());
    return 1;
  } catch (std::exception &e) {
    lua_pushfstring(L, "getCurrentFrame: %s", e.what());
  } catch (...) {
    lua_pushfstring(L, "getCurrentFrame: Unknown exception");
  }
  return dub_error(L);
}

/** int ofVideoPlayer::getTotalNumFrames()
 * api/openFrameworks/video/ofVideoPlayer.h:62
 */
static int ofVideoPlayer_getTotalNumFrames(lua_State *L) {
  try {
    ofVideoPlayer *self = *((ofVideoPlayer **)dub_checksdata(L, 1, "ofVideoPlayer"));
    lua_pushnumber(L, self->getTotalNumFrames());
    return 1;
  } catch (std::exception &e) {
    lua_pushfstring(L, "getTotalNumFrames: %s", e.what());
  } catch (...) {
    lua_pushfstring(L, "getTotalNumFrames: Unknown exception");
  }
  return dub_error(L);
}

/** void ofVideoPlayer::firstFrame()
 * api/openFrameworks/video/ofVideoPlayer.h:64
 */
static int ofVideoPlayer_firstFrame(lua_State *L) {
  try {
    ofVideoPlayer *self = *((ofVideoPlayer **)dub_checksdata(L, 1, "ofVideoPlayer"));
    self->firstFrame();
    return 0;
  } catch (std::exception &e) {
    lua_pushfstring(L, "firstFrame: %s", e.what());
  } catch (...) {
    lua_pushfstring(L, "firstFrame: Unknown exception");
  }
  return dub_error(L);
}

/** void ofVideoPlayer::nextFrame()
 * api/openFrameworks/video/ofVideoPlayer.h:65
 */
static int ofVideoPlayer_nextFrame(lua_State *L) {
  try {
    ofVideoPlayer *self = *((ofVideoPlayer **)dub_checksdata(L, 1, "ofVideoPlayer"));
    self->nextFrame();
    return 0;
  } catch (std::exception &e) {
    lua_pushfstring(L, "nextFrame: %s", e.what());
  } catch (...) {
    lua_pushfstring(L, "nextFrame: Unknown exception");
  }
  return dub_error(L);
}

/** void ofVideoPlayer::previousFrame()
 * api/openFrameworks/video/ofVideoPlayer.h:66
 */
static int ofVideoPlayer_previousFrame(lua_State *L) {
  try {
    ofVideoPlayer *self = *((ofVideoPlayer **)dub_checksdata(L, 1, "ofVideoPlayer"));
    self->previousFrame();
    return 0;
  } catch (std::exception &e) {
    lua_pushfstring(L, "previousFrame: %s", e.what());
  } catch (...) {
    lua_pushfstring(L, "previousFrame: Unknown exception");
  }
  return dub_error(L);
}

/** float ofVideoPlayer::getHeight()
 * api/openFrameworks/video/ofVideoPlayer.h:68
 */
static int ofVideoPlayer_getHeight(lua_State *L) {
  try {
    ofVideoPlayer *self = *((ofVideoPlayer **)dub_checksdata(L, 1, "ofVideoPlayer"));
    lua_pushnumber(L, self->getHeight());
    return 1;
  } catch (std::exception &e) {
    lua_pushfstring(L, "getHeight: %s", e.what());
  } catch (...) {
    lua_pushfstring(L, "getHeight: Unknown exception");
  }
  return dub_error(L);
}

/** float ofVideoPlayer::getWidth()
 * api/openFrameworks/video/ofVideoPlayer.h:69
 */
static int ofVideoPlayer_getWidth(lua_State *L) {
  try {
    ofVideoPlayer *self = *((ofVideoPlayer **)dub_checksdata(L, 1, "ofVideoPlayer"));
    lua_pushnumber(L, self->getWidth());
    return 1;
  } catch (std::exception &e) {
    lua_pushfstring(L, "getWidth: %s", e.what());
  } catch (...) {
    lua_pushfstring(L, "getWidth: Unknown exception");
  }
  return dub_error(L);
}

/** bool ofVideoPlayer::isPaused()
 * api/openFrameworks/video/ofVideoPlayer.h:71
 */
static int ofVideoPlayer_isPaused(lua_State *L) {
  try {
    ofVideoPlayer *self = *((ofVideoPlayer **)dub_checksdata(L, 1, "ofVideoPlayer"));
    lua_pushboolean(L, self->isPaused());
    return 1;
  } catch (std::exception &e) {
    lua_pushfstring(L, "isPaused: %s", e.what());
  } catch (...) {
    lua_pushfstring(L, "isPaused: Unknown exception");
  }
  return dub_error(L);
}

/** bool ofVideoPlayer::isLoaded()
 * api/openFrameworks/video/ofVideoPlayer.h:72
 */
static int ofVideoPlayer_isLoaded(lua_State *L) {
  try {
    ofVideoPlayer *self = *((ofVideoPlayer **)dub_checksdata(L, 1, "ofVideoPlayer"));
    lua_pushboolean(L, self->isLoaded());
    return 1;
  } catch (std::exception &e) {
    lua_pushfstring(L, "isLoaded: %s", e.what());
  } catch (...) {
    lua_pushfstring(L, "isLoaded: Unknown exception");
  }
  return dub_error(L);
}

/** bool ofVideoPlayer::isPlaying()
 * api/openFrameworks/video/ofVideoPlayer.h:73
 */
static int ofVideoPlayer_isPlaying(lua_State *L) {
  try {
    ofVideoPlayer *self = *((ofVideoPlayer **)dub_checksdata(L, 1, "ofVideoPlayer"));
    lua_pushboolean(L, self->isPlaying());
    return 1;
  } catch (std::exception &e) {
    lua_pushfstring(L, "isPlaying: %s", e.what());
  } catch (...) {
    lua_pushfstring(L, "isPlaying: Unknown exception");
  }
  return dub_error(L);
}

/** virtual unsigned char* ofBaseVideoPlayer::getPixels()=0
 * api/openFrameworks/types/ofBaseTypes.h:237
 */
static int ofVideoPlayer_getPixels(lua_State *L) {
  try {
    ofVideoPlayer *self = *((ofVideoPlayer **)dub_checksdata(L, 1, "ofVideoPlayer"));
    lua_pushstring(L, self->getPixels());
    return 1;
  } catch (std::exception &e) {
    lua_pushfstring(L, "getPixels: %s", e.what());
  } catch (...) {
    lua_pushfstring(L, "getPixels: Unknown exception");
  }
  return dub_error(L);
}

/** virtual ofTexture* ofBaseVideoPlayer::getTexture()
 * api/openFrameworks/types/ofBaseTypes.h:238
 */
static int ofVideoPlayer_getTexture(lua_State *L) {
  try {
    ofVideoPlayer *self = *((ofVideoPlayer **)dub_checksdata(L, 1, "ofVideoPlayer"));
    ofTexture *retval__ = self->getTexture();
    if (!retval__) return 0;
    dub_pushudata(L, retval__, "ofTexture", false);
    return 1;
  } catch (std::exception &e) {
    lua_pushfstring(L, "getTexture: %s", e.what());
  } catch (...) {
    lua_pushfstring(L, "getTexture: Unknown exception");
  }
  return dub_error(L);
}



// --=============================================== __tostring
static int ofVideoPlayer___tostring(lua_State *L) {
  ofVideoPlayer *self = *((ofVideoPlayer **)dub_checksdata_n(L, 1, "ofVideoPlayer"));
  lua_pushfstring(L, "ofVideoPlayer: %p", self);
  
  return 1;
}

// --=============================================== METHODS

static const struct luaL_Reg ofVideoPlayer_member_methods[] = {
  { "__gc"         , ofVideoPlayer__ofVideoPlayer },
  { "__newindex"   , ofVideoPlayer__set_  },
  { "__index"      , ofVideoPlayer__get_  },
  { "_cast_"       , ofVideoPlayer__cast_ },
  { "new"          , ofVideoPlayer_ofVideoPlayer },
  { "setPlayer"    , ofVideoPlayer_setPlayer },
  { "getPlayer"    , ofVideoPlayer_getPlayer },
  { "loadMovie"    , ofVideoPlayer_loadMovie },
  { "getMoviePath" , ofVideoPlayer_getMoviePath },
  { "setPixelFormat", ofVideoPlayer_setPixelFormat },
  { "getPixelFormat", ofVideoPlayer_getPixelFormat },
  { "closeMovie"   , ofVideoPlayer_closeMovie },
  { "close"        , ofVideoPlayer_close  },
  { "update"       , ofVideoPlayer_update },
  { "play"         , ofVideoPlayer_play   },
  { "stop"         , ofVideoPlayer_stop   },
  { "isFrameNew"   , ofVideoPlayer_isFrameNew },
  { "getPosition"  , ofVideoPlayer_getPosition },
  { "getSpeed"     , ofVideoPlayer_getSpeed },
  { "getDuration"  , ofVideoPlayer_getDuration },
  { "getIsMovieDone", ofVideoPlayer_getIsMovieDone },
  { "setPosition"  , ofVideoPlayer_setPosition },
  { "setVolume"    , ofVideoPlayer_setVolume },
  { "setLoopState" , ofVideoPlayer_setLoopState },
  { "getLoopState" , ofVideoPlayer_getLoopState },
  { "setSpeed"     , ofVideoPlayer_setSpeed },
  { "setFrame"     , ofVideoPlayer_setFrame },
  { "setUseTexture", ofVideoPlayer_setUseTexture },
  { "getTextureReference", ofVideoPlayer_getTextureReference },
  { "draw"         , ofVideoPlayer_draw   },
  { "setAnchorPercent", ofVideoPlayer_setAnchorPercent },
  { "setAnchorPoint", ofVideoPlayer_setAnchorPoint },
  { "resetAnchor"  , ofVideoPlayer_resetAnchor },
  { "setPaused"    , ofVideoPlayer_setPaused },
  { "getCurrentFrame", ofVideoPlayer_getCurrentFrame },
  { "getTotalNumFrames", ofVideoPlayer_getTotalNumFrames },
  { "firstFrame"   , ofVideoPlayer_firstFrame },
  { "nextFrame"    , ofVideoPlayer_nextFrame },
  { "previousFrame", ofVideoPlayer_previousFrame },
  { "getHeight"    , ofVideoPlayer_getHeight },
  { "getWidth"     , ofVideoPlayer_getWidth },
  { "isPaused"     , ofVideoPlayer_isPaused },
  { "isLoaded"     , ofVideoPlayer_isLoaded },
  { "isPlaying"    , ofVideoPlayer_isPlaying },
  { "getPixels"    , ofVideoPlayer_getPixels },
  { "getTexture"   , ofVideoPlayer_getTexture },
  { "__tostring"   , ofVideoPlayer___tostring },
  { "deleted"      , dub_isDeleted        },
  { NULL, NULL},
};


extern "C" int luaopen_ofVideoPlayer(lua_State *L)
{
  // Create the metatable which will contain all the member methods
  luaL_newmetatable(L, "ofVideoPlayer");
  // <mt>

  // register member methods
  luaL_register(L, NULL, ofVideoPlayer_member_methods);
  // save meta-table in _G
  dub_register(L, "_G", "ofVideoPlayer", "ofVideoPlayer");
  // <mt>
  lua_pop(L, 1);
  return 0;
}