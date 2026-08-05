# Scratch: `aa_004fbec0` VehicleEntity_SetDriveAxes (dual strengthen 2026-07-29)

## Live tools

* `decompile_function` @ `0x004fbec0`, `0x004fbc10`, `0x004f5650`, `0x004f5620`, `0x00598320`
* `read_memory` @ `0x004fbec0` len 48; @ `0x004fbeee` len 16; @ `0x00598570` len 48
* `get_function_callers` / `get_function_xrefs` / `get_bulk_xrefs` → sole site `0x0059858a`

## Body decode

```
movss thr; mov hb; movss [ecx+0x614]; movss steer; movss [ecx+0x618]; mov [ecx+0x61c]; call Push; ret 0xc
span 004fbec0..004fbeed (46 B); pad cc cc
call rel → 004fbc10
```

## Caller

airStab recovery: `mov ecx,[esi+44]; push 1; push 0; push 0; call` → thr0 steer0 hb1

## Sealed / open

Sealed: ungated three stores, always Push, types, sole static caller args, Push omits steer (via Push dual).
Open: runtime, indirect calls, external airStab doc wording (out of OWN).
