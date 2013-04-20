local f = io.popen("ls")
print f
for mod in f:lines() do
    require(mod)
end

ofSetupOpenGL(1024, 768, OF_WINDOW)

ofRunApp(app)
