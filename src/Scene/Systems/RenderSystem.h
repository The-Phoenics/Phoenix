#pragma once

inline void RenderPlayer();
inline void RenderMap();
inline void RenderEnemies();

inline void RenderSystem()
{
    RenderMap();
    RenderEnemies();
    // ---
    RenderPlayer();
}

inline void RenderPlayer()
{

}

inline void RenderMap()
{
    // ...
}

inline void RenderEnemies()
{
    // ...
}