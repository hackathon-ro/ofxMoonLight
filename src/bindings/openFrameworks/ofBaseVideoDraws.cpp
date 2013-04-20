/**
 *
 * MACHINE GENERATED FILE. DO NOT EDIT.
 *
 * Bindings for class ofBaseVideoDraws
 *
 * This file has been generated by dub 2.1.~.
 */
#include "dub/dub.h"
#include "api/openFrameworks/types/ofBaseTypes.h"


/** Cast (class_name)
 * 
 */
static int ofBaseVideoDraws__cast_(lua_State *L) {

  ofBaseVideoDraws *self = *((ofBaseVideoDraws **)dub_checksdata_n(L, 1, "ofBaseVideoDraws"));
  const char *key = luaL_checkstring(L, 2);
  void **retval__ = (void**)lua_newuserdata(L, sizeof(void*));
  int key_h = dub_hash(key, 2);
  switch(key_h) {
    case 1: {
      if (DUB_ASSERT_KEY(key, "ofBaseVideo")) break;
      *retval__ = static_cast<ofBaseVideo *>(self);
      return 1;
    }
    case 0: {
      if (DUB_ASSERT_KEY(key, "ofBaseUpdates")) break;
      *retval__ = static_cast<ofBaseUpdates *>(self);
      return 1;
    }
  }
  return 0;
}

/** ofBaseVideoDraws()
 * 
 */
static int ofBaseVideoDraws_ofBaseVideoDraws(lua_State *L) {
  try {
    ofBaseVideoDraws *retval__ = new ofBaseVideoDraws();
    dub_pushudata(L, retval__, "ofBaseVideoDraws", true);
    return 1;
  } catch (std::exception &e) {
    lua_pushfstring(L, "new: %s", e.what());
  } catch (...) {
    lua_pushfstring(L, "new: Unknown exception");
  }
  return dub_error(L);
}

/** virtual ofBaseVideoDraws::~ofBaseVideoDraws()
 * api/openFrameworks/types/ofBaseTypes.h:184
 */
static int ofBaseVideoDraws__ofBaseVideoDraws(lua_State *L) {
  try {
    DubUserdata *userdata = ((DubUserdata*)dub_checksdata_d(L, 1, "ofBaseVideoDraws"));
    if (userdata->gc) {
      ofBaseVideoDraws *self = (ofBaseVideoDraws *)userdata->ptr;
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

/** virtual bool ofBaseVideo::isFrameNew()=0
 * api/openFrameworks/types/ofBaseTypes.h:174
 */
static int ofBaseVideoDraws_isFrameNew(lua_State *L) {
  try {
    ofBaseVideoDraws *self = *((ofBaseVideoDraws **)dub_checksdata(L, 1, "ofBaseVideoDraws"));
    lua_pushboolean(L, self->isFrameNew());
    return 1;
  } catch (std::exception &e) {
    lua_pushfstring(L, "isFrameNew: %s", e.what());
  } catch (...) {
    lua_pushfstring(L, "isFrameNew: Unknown exception");
  }
  return dub_error(L);
}

/** virtual void ofBaseVideo::close()=0
 * api/openFrameworks/types/ofBaseTypes.h:175
 */
static int ofBaseVideoDraws_close(lua_State *L) {
  try {
    ofBaseVideoDraws *self = *((ofBaseVideoDraws **)dub_checksdata(L, 1, "ofBaseVideoDraws"));
    self->close();
    return 0;
  } catch (std::exception &e) {
    lua_pushfstring(L, "close: %s", e.what());
  } catch (...) {
    lua_pushfstring(L, "close: Unknown exception");
  }
  return dub_error(L);
}

/** virtual void ofBaseUpdates::update()=0
 * api/openFrameworks/types/ofBaseTypes.h:69
 */
static int ofBaseVideoDraws_update(lua_State *L) {
  try {
    ofBaseVideoDraws *self = *((ofBaseVideoDraws **)dub_checksdata(L, 1, "ofBaseVideoDraws"));
    self->update();
    return 0;
  } catch (std::exception &e) {
    lua_pushfstring(L, "update: %s", e.what());
  } catch (...) {
    lua_pushfstring(L, "update: Unknown exception");
  }
  return dub_error(L);
}



// --=============================================== __tostring
static int ofBaseVideoDraws___tostring(lua_State *L) {
  ofBaseVideoDraws *self = *((ofBaseVideoDraws **)dub_checksdata_n(L, 1, "ofBaseVideoDraws"));
  lua_pushfstring(L, "ofBaseVideoDraws: %p", self);
  
  return 1;
}

// --=============================================== METHODS

static const struct luaL_Reg ofBaseVideoDraws_member_methods[] = {
  { "_cast_"       , ofBaseVideoDraws__cast_ },
  { "new"          , ofBaseVideoDraws_ofBaseVideoDraws },
  { "__gc"         , ofBaseVideoDraws__ofBaseVideoDraws },
  { "isFrameNew"   , ofBaseVideoDraws_isFrameNew },
  { "close"        , ofBaseVideoDraws_close },
  { "update"       , ofBaseVideoDraws_update },
  { "__tostring"   , ofBaseVideoDraws___tostring },
  { "deleted"      , dub_isDeleted        },
  { NULL, NULL},
};


extern "C" int luaopen_ofBaseVideoDraws(lua_State *L)
{
  // Create the metatable which will contain all the member methods
  luaL_newmetatable(L, "ofBaseVideoDraws");
  // <mt>

  // register member methods
  luaL_register(L, NULL, ofBaseVideoDraws_member_methods);
  // save meta-table in _G
  dub_register(L, "_G", "ofBaseVideoDraws", "ofBaseVideoDraws");
  // <mt>
  lua_pop(L, 1);
  return 0;
}