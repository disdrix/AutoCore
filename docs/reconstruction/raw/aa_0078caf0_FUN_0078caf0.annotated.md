# Annotated low-level: CNDUIWndBuffered_Ctor_Inferred

| Field | Value |
|---|---|
| Stable ID | `aa_0078caf0` |
| VA | `0x0078caf0`–`0x0078cecb` exclusive (**987 B** / `0x3DB`) |
| System | client / ND UI buffered window |
| Date | 2026-07-29 (W34-T dual seal) |
| Prior scaffold | `FUN_0078caf0` |

## Machine-level notes

- Source: raw capture + W34-T live decompile / `read_memory_bytes` / RTTI COL.
- Host class **Confirmed**: `.?AVCNDUIWndBuffered@@` via vtbl `PTR_FUN_00a99f74`.
- Instance size **0x4FC** (`operator_new(0x4FC)` at three call sites).
- ABI: stack `this` + 2 formals; `ret 12`; returns `this`.

## Pseudocode (annotated)

```c
// ret 12; returns this
CNDUIWndBuffered *CNDUIWndBuffered_Ctor_Inferred(
    CNDUIWndBuffered *self,
    uint32_t arg1,     // forwarded to CNDUIWindow base
    uint32_t arg2)     // stored at +0x488
{
  // SEH LAB_009b400b
  CNDUIWindow_Ctor_Inferred(self, arg1);   // FUN_007b5dd0; vtbl CNDUIWindow

  *self = &PTR_FUN_00a99f74;               // CNDUIWndBuffered vtbl

  // Field bank (high-level): clear/init color/flag rows in +0x4A0..+0x4F8 region,
  // identity float blocks, defaults from DAT_* / g_flOne / 1/255 color scale.
  // self[+0x134] = 2.0f (DAT_00a10e74; decomp name g_flLevelUpUiBase_Inferred misnomer)
  // self[+0x488] = arg2
  // flags: +0xBE/+0xBF = 1; +0x48C = 0x10; several byte flags zeroed after FF seed

  self->hostBase = 0; // +0x2A8 cleared via later assign
  // zero +0x228..+0x230, +0x2AC, +0x49C

  void *raw = operator_new(0x80);
  HostBase *host = (raw == nullptr) ? nullptr : HostBase_DefaultCtor(raw); // FUN_007560d0
  *(HostBase **)((char *)self + 0x2A8) = host;
  HostBase_EnsureAuxPtrs_Inferred(host, 1); // FUN_00756320; ECX=host even if null path

  return self;
}
```

## Subclass RTTI (callers install after this)

| Subclass ctor | Vtbl RTTI |
|---|---|
| `FUN_00856490` | `CWndPortrait` |
| `FUN_008345c0` | `CWndVehicle` |
| `FUN_0097c720` | `CWndParticles` |

## Open questions

- Product English for `arg1` / `arg2` formals (factory constants 0/1 only observed).
- Full field map / color bank product meaning beyond scaled literals.
- Exact product name for nested HostBase type (W32-O/Q residual).
- Runtime / bit-exact / differential.
