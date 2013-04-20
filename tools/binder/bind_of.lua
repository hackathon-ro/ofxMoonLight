--[[------------------------------------------------------
 
 openFrameworks bindings generator
 ---------------------------------
 
 This uses the 'dub' tool and Doxygen to generate the
 bindings for openFrameworks.
 
 --]]------------------------------------------------------
require 'lubyk'

-- 5 = show all warnings
dub.warn_level = 4

local base = lk.scriptDir()
local of_base = lk.scriptDir() .. '/api/openFrameworks'

if not lk.exist(of_base) then
    print ('openFrameworks NOT FOUND')
    return
end

local gen_dir = base ..'/bindings/openFrameworks'

local format = string.format

-- binding for any pointer type
local handlePointer = function(pointer_type)
return {
    type   = pointer_type,
    -- Get value from Lua.
    pull   = function(name, position, prefix)
    return format('%s %s = (%s) lua_touserdata (L, %i);\n',
                  pointer_type, name, pointer_type, position)
    end,
    -- Push value in Lua
    push   = function(name)
    return format('lua_pushlightuserdata(L, (void *)%s);', name)
    end,
    cast   = function(name)
    return format('(%s) %s', pointer_type, name)
    end,
}
end

local custom_types =
{
    ['BOOL'] = 'boolean',
    ['long'] = 'int',
    ['unsigned long'] = 'int',
    ['unsigned long long'] = 'int',
    ['long unsigned long'] = 'int',
    ['float const const'] = 'number',
    
    ['int *'] = handlePointer('int *'),
    ['unsigned int *'] = handlePointer('unsigned int *'),
    ['unsigned short *'] = handlePointer('unsigned short *'),
    ['float *'] = handlePointer('float *'),
    ['unsigned charconst *'] = 'string',
    ['char* *'] = handlePointer('char* *'),
    
    ['string'] = {
        type   = 'string',
        -- Get value from Lua.
        pull   = function(name, position, prefix)
        return format('size_t %s_sz_;\nconst char *%s = %schecklstring(L, %i, &%s_sz_);',
                      name, name, prefix, position, name)
        end,
        -- Push value in Lua
        push   = function(name)
        return format('lua_pushlstring(L, %s.data(), %s.length());', name, name)
        end,
        -- Cast value
        cast   = function(name)
        return format('std::string(%s, %s_sz_)', name, name)
        end,
    },
    
    ['GLenum'] = 'int',
    ['GLint'] = 'int',
    ['GLuint'] = 'int',
    ['GLfloat'] = 'number',
    
    ['enum ofTouchEventArgs::Type'] = 'int',
    ['ofIndexType'] = 'int',
    ['IndexType'] = 'int',    
}




local binder = dub.LuaBinder()

binder:addCustomTypes(custom_types)

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
        
        base..'/../../src/app/',
    },
    
    html = false,
}

-- remove gen directory
lk.rmTree(gen_dir, true)
-- create gen directory
os.execute('mkdir -p ' .. gen_dir)

binder:bind(ins, {
            output_directory = gen_dir,
            
            ignore = {
                
                -- app
                -- base and abstract
                'ofAppBaseWindow',
                'ofBaseApp',
                
                -- communication
                'ofSerial',
                'ofSerialDeviceInfo',
            
                -- typedefs
                'ofFloatColor',
                'ofShortImage',
                'ofFloatImage',
                
                -- graphics
                --base and abstract
                'ofBaseRenderer',
                'ofAbstractHasPixels',
                'ofAbstractImage',
                'charProps',
                -- typedefs
                'ofShortPixels',
                'ofFloatPixels',
                
                -- sound
                --base and abstract
                'ofBaseSoundInput',
                'ofBaseSoundOutput',
                
                --types
                -- base and abstract
                'ofBaseDraws',
                'ofBaseHasTexture',
                'ofBaseUpdates',

                -- utils
                -- base and abstract
                'ofBaseLoggerChannel',
                'ofFileDialogResult',
                
                -- video
                -- base and abstract
                'ofBaseVideo',
                'ofBaseVideoDraws',
                'ofBaseVideoGrabber',
                'ofBaseVideoPlayer',
            },
            
            -- Removes this part in generated headers
            header_base = {
                of_base,
                base..'/../../src/'
            },
            -- Execute all lua_open in a single go
            -- with luaopen_of (creates of.cpp).
            single_lib = 'of',
    
            -- just use the classes provided, with their 'of' prefix
            lib_prefix = false,
            
            })
