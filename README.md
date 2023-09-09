# D3D11-SwapChain-Hook

Easy to use D3D11 SwapChain Dummy Method Wrapper

```
bool Initialize()
{
		D3D11Hook DirectXHook;

		Hook(DirectXHook.GetPresentFunction(), Present::hkPresent); // Hook Present
		Hook(DirectXHook.GetResizeBuffersFunction(), ResizeBuffers::hkResizeBuffer); // Hook Resize

		return true;
}
```
