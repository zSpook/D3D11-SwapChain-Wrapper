#pragma once

#include <d3d11.h>

typedef HRESULT(__fastcall* PresentFN)(IDXGISwapChain* SwapChain, UINT SyncInterval, UINT Flags);
typedef HRESULT(__fastcall* ResizeBuffersFN)(IDXGISwapChain* SwapChain, UINT BufferCount, UINT Widht, UINT Height, DXGI_FORMAT NewFormat, UINT SwapChainFlags);

class D3D11Hook
{
public:
	D3D11Hook() { Initialize(); }
	~D3D11Hook() { }

	bool Initialize();

	void** GetSwapChainTable() { return SwapChainTable; }
	PresentFN GetPresentFunction() { return (PresentFN)SwapChainTable[8]; }
	ResizeBuffersFN GetResizeBuffersFunction() { return (ResizeBuffersFN)SwapChainTable[13]; }

private:
	void** SwapChainTable;
};