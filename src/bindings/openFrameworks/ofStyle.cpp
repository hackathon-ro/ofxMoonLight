/**
 *
 * MACHINE GENERATED FILE. DO NOT EDIT.
 *
 * Bindings for class ofStyle
 *
 * This file has been generated by dub 2.1.~.
 */
#include "dub/dub.h"
#include "types/ofTypes.h"


/** Set attributes (key, value)
 * 
 */
static int ofStyle__set_(lua_State *L) {

  ofStyle *self = *((ofStyle **)dub_checksdata_n(L, 1, "ofStyle"));
  const char *key = luaL_checkstring(L, 2);
  int key_h = dub_hash(key, 34);
  switch(key_h) {
    case 5: {
      if (DUB_ASSERT_KEY(key, "color")) break;
      self->color = **((ofColor **)dub_checksdata_n(L, 3, "ofColor"));
      return 0;
    }
    case 18: {
      if (DUB_ASSERT_KEY(key, "bgColor")) break;
      self->bgColor = **((ofColor **)dub_checksdata_n(L, 3, "ofColor"));
      return 0;
    }
    case 15: {
      if (DUB_ASSERT_KEY(key, "polyMode")) break;
      self->polyMode = (ofPolyWindingMode)luaL_checkint(L, 3);
      return 0;
    }
    case 7: {
      if (DUB_ASSERT_KEY(key, "rectMode")) break;
      self->rectMode = (ofRectMode)luaL_checkint(L, 3);
      return 0;
    }
    case 27: {
      if (DUB_ASSERT_KEY(key, "bFill")) break;
      self->bFill = luaL_checkboolean(L, 3);
      return 0;
    }
    case 30: {
      if (DUB_ASSERT_KEY(key, "drawBitmapMode")) break;
      self->drawBitmapMode = (ofDrawBitmapMode)luaL_checkint(L, 3);
      return 0;
    }
    case 20: {
      if (DUB_ASSERT_KEY(key, "blendingMode")) break;
      self->blendingMode = (ofBlendMode)luaL_checkint(L, 3);
      return 0;
    }
    case 10: {
      if (DUB_ASSERT_KEY(key, "smoothing")) break;
      self->smoothing = luaL_checkboolean(L, 3);
      return 0;
    }
    case 4: {
      if (DUB_ASSERT_KEY(key, "circleResolution")) break;
      self->circleResolution = luaL_checkint(L, 3);
      return 0;
    }
    case 3: {
      if (DUB_ASSERT_KEY(key, "sphereResolution")) break;
      self->sphereResolution = luaL_checkint(L, 3);
      return 0;
    }
    case 1: {
      if (DUB_ASSERT_KEY(key, "curveResolution")) break;
      self->curveResolution = luaL_checkint(L, 3);
      return 0;
    }
    case 32: {
      if (DUB_ASSERT_KEY(key, "lineWidth")) break;
      self->lineWidth = luaL_checknumber(L, 3);
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
static int ofStyle__get_(lua_State *L) {

  ofStyle *self = *((ofStyle **)dub_checksdata_n(L, 1, "ofStyle", true));
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
  int key_h = dub_hash(key, 34);
  switch(key_h) {
    case 5: {
      if (DUB_ASSERT_KEY(key, "color")) break;
      dub_pushudata(L, &self->color, "ofColor", false);
      return 1;
    }
    case 18: {
      if (DUB_ASSERT_KEY(key, "bgColor")) break;
      dub_pushudata(L, &self->bgColor, "ofColor", false);
      return 1;
    }
    case 15: {
      if (DUB_ASSERT_KEY(key, "polyMode")) break;
      lua_pushnumber(L, self->polyMode);
      return 1;
    }
    case 7: {
      if (DUB_ASSERT_KEY(key, "rectMode")) break;
      lua_pushnumber(L, self->rectMode);
      return 1;
    }
    case 27: {
      if (DUB_ASSERT_KEY(key, "bFill")) break;
      lua_pushboolean(L, self->bFill);
      return 1;
    }
    case 30: {
      if (DUB_ASSERT_KEY(key, "drawBitmapMode")) break;
      lua_pushnumber(L, self->drawBitmapMode);
      return 1;
    }
    case 20: {
      if (DUB_ASSERT_KEY(key, "blendingMode")) break;
      lua_pushnumber(L, self->blendingMode);
      return 1;
    }
    case 10: {
      if (DUB_ASSERT_KEY(key, "smoothing")) break;
      lua_pushboolean(L, self->smoothing);
      return 1;
    }
    case 4: {
      if (DUB_ASSERT_KEY(key, "circleResolution")) break;
      lua_pushnumber(L, self->circleResolution);
      return 1;
    }
    case 3: {
      if (DUB_ASSERT_KEY(key, "sphereResolution")) break;
      lua_pushnumber(L, self->sphereResolution);
      return 1;
    }
    case 1: {
      if (DUB_ASSERT_KEY(key, "curveResolution")) break;
      lua_pushnumber(L, self->curveResolution);
      return 1;
    }
    case 32: {
      if (DUB_ASSERT_KEY(key, "lineWidth")) break;
      lua_pushnumber(L, self->lineWidth);
      return 1;
    }
  }
  return 0;
}

/** ofStyle::ofStyle()
 * api/openFrameworks/types/ofTypes.h:40
 */
static int ofStyle_ofStyle(lua_State *L) {
  try {
    ofStyle *retval__ = new ofStyle();
    dub_pushudata(L, retval__, "ofStyle", true);
    return 1;
  } catch (std::exception &e) {
    lua_pushfstring(L, "new: %s", e.what());
  } catch (...) {
    lua_pushfstring(L, "new: Unknown exception");
  }
  return dub_error(L);
}

/** virtual ofStyle::~ofStyle()
 * api/openFrameworks/types/ofTypes.h:54
 */
static int ofStyle__ofStyle(lua_State *L) {
  try {
    DubUserdata *userdata = ((DubUserdata*)dub_checksdata_d(L, 1, "ofStyle"));
    if (userdata->gc) {
      ofStyle *self = (ofStyle *)userdata->ptr;
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



// --=============================================== __tostring
static int ofStyle___tostring(lua_State *L) {
  ofStyle *self = *((ofStyle **)dub_checksdata_n(L, 1, "ofStyle"));
  lua_pushfstring(L, "ofStyle: %p", self);
  
  return 1;
}

// --=============================================== METHODS

static const struct luaL_Reg ofStyle_member_methods[] = {
  { "__newindex"   , ofStyle__set_        },
  { "__index"      , ofStyle__get_        },
  { "new"          , ofStyle_ofStyle      },
  { "__gc"         , ofStyle__ofStyle     },
  { "__tostring"   , ofStyle___tostring   },
  { "deleted"      , dub_isDeleted        },
  { NULL, NULL},
};


extern "C" int luaopen_ofStyle(lua_State *L)
{
  // Create the metatable which will contain all the member methods
  luaL_newmetatable(L, "ofStyle");
  // <mt>

  // register member methods
  luaL_register(L, NULL, ofStyle_member_methods);
  // save meta-table in _G
  dub_register(L, "_G", "ofStyle", "ofStyle");
  // <mt>
  lua_pop(L, 1);
  return 0;
}
