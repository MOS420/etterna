#ifndef RAGE_TEXTURE_MANAGER_H
#define RAGE_TEXTURE_MANAGER_H

/*
-----------------------------------------------------------------------------
 Class: RageTextureManager

 Desc: Interface for loading and releasing textures.

 Copyright (c) 2001-2002 by the person(s) listed below.  All rights reserved.
	Chris Danford
-----------------------------------------------------------------------------
*/
#include "RageTexture.h"

#include <map>

//-----------------------------------------------------------------------------
// RageTextureManager Class Declarations
//-----------------------------------------------------------------------------
class RageTextureManager
{
public:
	RageTextureManager();
	void Update( float fDeltaTime );
	~RageTextureManager();

	RageTexture* LoadTexture( RageTextureID ID );
	bool IsTextureRegistered( RageTextureID ID ) const;
	void RegisterTexture( RageTextureID ID, RageTexture *p );
	void CacheTexture( RageTextureID ID );
	void UnloadTexture( RageTexture *t );
	void ReloadAll();

	bool SetPrefs( int iTextureColorDepth, bool bDelayedDelete, int iMaxTextureResolution );
	int GetTextureColorDepth() { return m_iTextureColorDepth; };
	bool GetDelayedDelete() { return m_bDelayedDelete; };
	int GetMaxTextureResolution() { return m_iMaxTextureResolution; };

	// call this between Screens
	void DeleteCachedTextures()	{ GarbageCollect(cached_textures); }
	
	// call this on switch theme
	void DoDelayedDelete()	{ GarbageCollect(delayed_delete); }
	
	void InvalidateTextures();
	
	void AdjustTextureID(RageTextureID &ID) const;
	void DiagnosticOutput() const;

protected:
	void DeleteTexture( RageTexture *t );
	enum GCType { cached_textures, delayed_delete };
	void GarbageCollect( GCType type );

	int m_iTextureColorDepth;
	bool m_bDelayedDelete;
	int m_iMaxTextureResolution;

	std::map<RageTextureID, RageTexture*> m_mapPathToTexture;
};

extern RageTextureManager*	TEXTUREMAN;	// global and accessable from anywhere in our program

#endif
