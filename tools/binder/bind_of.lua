--[[------------------------------------------------------
 
 openFrameworks bindings generator
 ---------------------------------
 
 This uses the 'dub' tool and Doxygen to generate the
 bindings for openFrameworks.
 
 --]]------------------------------------------------------
require 'lubyk'

local base = lk.scriptDir()
local of_base = lk.scriptDir() .. '/api/openFrameworks'

if not lk.exist(of_base) then
    print ('openFrameworks NOT FOUND')
    return
end

local gen_dir = base ..'/bindings/openFrameworks'

local format = string.format

local binder = dub.LuaBinder()

--=============================================== Bind

local ins = dub.Inspector {
    INPUT   = {
        of_base .. '/3d/of3dUtils.h',
        of_base .. '/3d/ofCamera.h',
        of_base .. '/3d/ofEasyCam.h',
        of_base .. '/3d/ofMesh.h',
        of_base .. '/3d/ofNode.h',
        of_base .. '/app/ofAppBaseWindow.h',
        of_base .. '/app/ofAppRunner.h',
        of_base .. '/app/ofBaseApp.h',
        of_base .. '/events/ofEvents.h',
        of_base .. '/events/ofEventUtils.h',
        of_base .. '/gl/ofFbo.h',
        of_base .. '/gl/ofGLUtils.h',
        of_base .. '/gl/ofLight.h',
        of_base .. '/gl/ofMaterial.h',
        of_base .. '/gl/ofShader.h',
        of_base .. '/gl/ofTexture.h',
        of_base .. '/gl/ofVbo.h',
        of_base .. '/gl/ofVboMesh.h',
        of_base .. '/graphics/ofBitmapFont.h',
        of_base .. '/graphics/ofGraphics.h',
        of_base .. '/graphics/ofImage.h',
        of_base .. '/graphics/ofPath.h',
        of_base .. '/graphics/ofPixels.h',
        of_base .. '/graphics/ofPolyline.h',
        of_base .. '/graphics/ofTessellator.h',
        of_base .. '/graphics/ofTrueTypeFont.h',
        of_base .. '/math/ofMath.h',
        of_base .. '/math/ofMatrix3x3.h',
        of_base .. '/math/ofMatrix4x4.h',
        of_base .. '/math/ofQuaternion.h',
        of_base .. '/math/ofVec2f.h',
        of_base .. '/math/ofVec3f.h',
        of_base .. '/math/ofVec4f.h',
        of_base .. '/sound/ofSoundPlayer.h',
        of_base .. '/sound/ofSoundStream.h',
        of_base .. '/types/ofBaseTypes.h',
        of_base .. '/types/ofColor.h',
        of_base .. '/types/ofPoint.h',
        of_base .. '/types/ofRectangle.h',
        of_base .. '/types/ofTypes.h',
        of_base .. '/utils/ofConstants.h',
        of_base .. '/utils/ofFileUtils.h',
        of_base .. '/utils/ofLog.h',
        of_base .. '/utils/ofNoise.h',
        of_base .. '/utils/ofSystemUtils.h',
        of_base .. '/utils/ofThread.h',
        of_base .. '/utils/ofURLFileLoader.h',
        of_base .. '/utils/ofUtils.h',
        of_base .. '/video/ofVideoGrabber.h',
        of_base .. '/video/ofVideoPlayer.h',
        base..'/../../src/',
    },
    
    html = false,
}

-- remove gen directory
lk.rmTree(gen_dir, true)
-- create gen directory
os.execute('mkdir -p ' .. gen_dir)

binder:bind(ins, {
            output_directory = gen_dir,
            -- Execute all lua_open in a single go
            -- with luaopen_of (creates of.cpp).
            single_lib = 'of',
    
            -- just use the classes provided, with their 'of' prefix
            lib_prefix = false,
            
            })
