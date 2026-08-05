# Raw capture: FUN_0078caf0

| Field | Value |
|---|---|
| **Stable ID** | `aa_0078caf0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x0078caf0` |
| **Canonical name** | `FUN_0078caf0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 * FUN_0078caf0(undefined4 *param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  undefined4 uVar2;
  void *pvVar3;
  undefined4 uVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  float fVar9;
  void *local_c;
  undefined1 *puStack_8;
  int local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_009b400b;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  FUN_007b5dd0(param_1,param_2);
  fVar9 = g_flOne;
  local_4 = 0;
  *param_1 = &PTR_FUN_00a99f74;
  *(undefined1 *)((int)param_1 + 0x4a6) = 0xff;
  *(undefined1 *)((int)param_1 + 0x4a5) = 0xff;
  *(undefined1 *)(param_1 + 0x129) = 0xff;
  *(undefined1 *)((int)param_1 + 0x4a7) = 0xff;
  param_1[0x12a] = 0;
  param_1[299] = 0;
  param_1[300] = 0;
  param_1[0x12d] = fVar9;
  param_1[0x12e] = 0;
  param_1[0x12f] = 0;
  param_1[0x130] = 0;
  param_1[0x131] = fVar9;
  param_1[0x132] = 0;
  param_1[0x133] = 0;
  param_1[0x134] = 0;
  param_1[0x135] = fVar9;
  param_1[0x136] = 0;
  param_1[0x137] = 0;
  param_1[0x138] = 0;
  param_1[0x139] = fVar9;
  param_1[0x13a] = 0;
  param_1[0x13b] = 0;
  param_1[0x13c] = 0;
  fVar5 = g_flLevelUpUiBase_Inferred;
  param_1[0x13d] = fVar9;
  param_1[0x4d] = fVar5;
  uVar4 = DAT_00a0f710;
  param_1[0x122] = param_3;
  uVar2 = DAT_00aaabbc;
  *(undefined1 *)(param_1 + 0x13e) = 0;
  *(undefined1 *)((int)param_1 + 0xbe) = 1;
  *(undefined1 *)((int)param_1 + 0xbf) = 1;
  param_1[0x123] = 0x10;
  *(undefined1 *)((int)param_1 + 0x4a1) = 0;
  *(undefined1 *)(param_1 + 0x128) = 0;
  *(undefined1 *)((int)param_1 + 0x4a6) = 0;
  *(undefined1 *)((int)param_1 + 0x4a5) = 0;
  *(undefined1 *)(param_1 + 0x129) = 0;
  *(undefined1 *)((int)param_1 + 0x4a7) = 0;
  uVar1 = DAT_00a0f720;
  param_1[0x124] = uVar4;
  uVar4 = DAT_00a0f298;
  param_1[0x125] = uVar2;
  param_1[0x126] = uVar1;
  param_1[0x12a] = fVar9;
  param_1[299] = fVar9;
  param_1[300] = fVar9;
  param_1[0x12d] = fVar9;
  fVar5 = DAT_00b017e8;
  param_1[0x12e] = uVar4;
  param_1[0x12f] = uVar4;
  param_1[0x130] = uVar4;
  fVar6 = fVar5 * _DAT_00aaaa68;
  param_1[0x132] = fVar9;
  param_1[0x131] = fVar9;
  param_1[0x133] = fVar9;
  fVar7 = fVar5 * _DAT_00aaaa64;
  param_1[0x134] = fVar9;
  fVar8 = fVar5 * _DAT_00aaaa60;
  param_1[0x136] = fVar6;
  fVar6 = fVar5 * _DAT_00aaaa5c;
  param_1[0x135] = fVar9;
  param_1[0x137] = fVar7;
  fVar9 = fVar5 * DAT_00aaa6f8;
  fVar7 = fVar5 * _DAT_00aaaa58;
  fVar5 = fVar5 * _DAT_00aaa7c0;
  param_1[0x138] = fVar8;
  param_1[0x13a] = fVar6;
  param_1[0x139] = fVar9;
  param_1[0x13b] = fVar7;
  param_1[0x13c] = fVar5;
  param_1[0x13d] = fVar9;
  param_1[0xab] = 0;
  param_1[0x127] = 0;
  param_1[0x8a] = 0;
  param_1[0x8b] = 0;
  param_1[0x8c] = 0;
  pvVar3 = operator_new(0x80);
  local_4._0_1_ = 1;
  if (pvVar3 == (void *)0x0) {
    uVar4 = 0;
  }
  else {
    uVar4 = FUN_007560d0();
  }
  local_4 = (uint)local_4._1_3_ << 8;
  param_1[0xaa] = uVar4;
  FUN_00756320(1);
  ExceptionList = local_c;
  return param_1;
}
```

---

## W34-T live re-verify (2026-07-29)

**Tools:** Ghidra decompile_function + get_function_by_address + xrefs/callers/callees + ead_memory_bytes + MSVC RTTI COL walk. **No** disassemble_bytes.

### Body / ABI (bytes)

- Body: `0x0078caf0`â€“`0x0078cecb` exclusive (**987 B** / `0x3DB`). Final `C2 0C 00` (`ret 12`); pad `CC`. SEH `LAB_009b400b`.
- ABI: **3 stack formals** cleaned by `ret 12`; first = `this*` (call sites `push esi/eax`); returns `this` in EAX. Entry loads this from stack (not ECX) â€” Ghidra 3-arg form matches call-site pushes.
- Signature: `CNDUIWndBuffered* CNDUIWndBuffered_Ctor_Inferred(CNDUIWndBuffered* this, uint32_t arg1, uint32_t arg2)`.

### Host RTTI (**Confirmed**)

- Installs vtbl `PTR_FUN_00a99f74`.
- COL @ `vtable-4` â†’ `0x00ab8280` â†’ type_info `0x00afe4d0` â†’ **`.?AVCNDUIWndBuffered@@`** â†’ class **`CNDUIWndBuffered`**.
- Hierarchy (CHD bases): `CNDUIWndBuffered` : `CNDUIWindow` : `gfxUIWindow`.
- Peer base ctor `FUN_007b5dd0` installs `PTR_FUN_00a960ac` â†’ **`.?AVCNDUIWindow@@`**.

### Algorithm (sealed)

1. SEH frame; `FUN_007b5dd0(this, arg1)` â€” `CNDUIWindow` base complete ctor.
2. `*this = PTR_FUN_00a99f74` (CNDUIWndBuffered vtbl).
3. Init buffered-window field bank (identity-ish float rows, flags, colors scaled by `DAT_00b017e8`â‰ˆ1/255 Ã— constants 112/123/143/62/255/47/45, `g_flOne`, `0.5`, `0.7`, `0.4`, `-0.55`, `param_1[0x4d]=2.0f` @ `DAT_00a10e74` mislabeled `g_flLevelUpUiBase_Inferred`).
4. Store `arg2` at dword `+0x488` (`param_1[0x122]`).
5. Zero triple `+0x228/+0x22c/+0x230` (`[0x8a..0x8c]`); `+0x2AC` (`[0xab]`); `+0x49C` (`[0x127]`).
6. `operator_new(0x80)` + `FUN_007560d0` (HostBase default ctor) â†’ slot dword `+0x2A8` (`param_1[0xaa]`); null on OOM.
7. `HostBase_EnsureAuxPtrs_Inferred(host, 1)` on that nested host (`FUN_00756320`).
8. Return `this`.

### Alloc size

Direct `operator_new(0x4FC)` before this ctor at three sites (`68 FC 04 00 00`). **Instance size 0x4FC**.

### Callers (6 CODE xrefs)

| Site | Enclosing | Notes |
|------|-----------|-------|
| `0x008564b0` | `FUN_00856490` | subclass ctor; vtbl â†’ **CWndPortrait**; args `(this,0,0)` |
| `0x008345e1` | `FUN_008345c0` | subclass ctor; vtbl â†’ **CWndVehicle**; args `(this,0,1)` |
| `0x0097c741` | `FUN_0097c720` | subclass ctor; vtbl â†’ **CWndParticles**; args `(this,0,1)` |
| `0x008ff47d` | `FUN_008ff260` | `new(0x4FC)` + ctor |
| `0x008a9cdc` | `FUN_008a9af0` | `new(0x4FC)` + ctor `(p,0,1)` |
| `0x008e6d8d` | `FUN_008e6b50` | `new(0x4FC)` + ctor `(p,?,1)` |

### Live decompile â‰¡ raw CF

Live 2026-07-29 â‰¡ 2026-07-23 raw (base ctor â†’ vtbl â†’ field bank â†’ HostBase new/ensure â†’ return this).

### Related

- Complete dtor peer `FUN_0078ca80` (same vtbl; tears HostBase @ `+0xaa`).
- `HostBase_DefaultCtor` `FUN_007560d0` (W32-O); `HostBase_EnsureAuxPtrs` `FUN_00756320` (W32-Q).

