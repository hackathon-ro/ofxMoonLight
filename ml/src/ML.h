#pragma once

#include "ofConstants.h"
#include "ofEvents.h"

// make sure these 2 macros are not defined
// (I'm looking at you, Mac OS AssertMacros.h!)
#ifdef check
	#undef check
#endif
#ifdef nil
	#undef nil
#endif

#include "lua.hpp"

extern "C" {
    int luaopen_of(lua_State *L);
}

///
/// a baseclass to receieve lua error messages,
/// useful for displaying an error message on the screen, etc
///
class MLListener {

	public :
	
		virtual void errorReceived(string& msg) = 0;
};

///
///	a Lua interpreter instance
///
///	references:
///		- lua api http://pgl.yoyo.org/luai/i/_
///
class ML {
	
	public :

		ML();
		virtual ~ML();
        
		/// init the lua state
		///
		/// set abortOnError to true if you want the lua state to be cleared
		/// when an error ocurrs
		///
		/// set openLibs to false if you don't want to load the
		/// standard lua libs (math, io, string, etc)
		///
		/// note: calls clear if the state has already been inited
		///
		bool init(bool abortOnError=false, bool openLibs=true);
		
		/// is this state valid? (inited, not aborted, etc)
		bool isValid();
		
		/// get/set abort on error
		/// if abort on error is true, the state is closed when an error ocurrs
		bool getAbortOnError()				{return bAbortOnError;}
		void setAbortOnError(bool abort)	{bAbortOnError = abort;}
		
	/// \section Running Lua code
		
		/// run a lua string, returns false on script error
		bool doString(const string& text);
		
		/// run a lua script, returns false on script error
		bool doScript(const string& script);
		
	/// \section Listeners
		
		/// add a listener, ignores any duplicates
		void addListener(MLListener* listener);
		
		/// remove a listener
		void removeListener(MLListener* listener);
		
	/// \section Util
		
		operator lua_State*() const {return L;}
        		
    protected:
		
		/// send a lua error message to ofLog and any listeners
		virtual void errorOccurred(string& msg);
		
		/// called when lua state panics
		static int atPanic(lua_State *L);
	
		lua_State* L;			//< the lua state object
		bool bAbortOnError;		//< close the lua state on error?
		ofEvent<string> errorEvent; //< error event object, string is error msg
		string errorMessage; //< current error message
};
