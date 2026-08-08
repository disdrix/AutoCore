# Raw capture: FUN_005ebec0

| Field | Value |
|---|---|
| **Stable ID** | `aa_005ebec0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x005ebec0` |
| **Canonical name** | `FUN_005ebec0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
undefined4 * __thiscall FUN_005ebec0(undefined4 *param_1,undefined4 param_2)

{
  FUN_005eb210(param_2);
  *param_1 = &PTR_FUN_009dce90;
  param_1[0x30] = 0;
  param_1[0x31] = 0;
  param_1[0x32] = 0x80000000;
  return param_1;
}
```

---

## MEGA-070 live re-verify (2026-08-05) — APPEND ONLY

**Agent:** OWN-ONLY dual **MEGA-070**  
**Tools:** Ghidra decompile_function + nalyze_function_complete + disassemble_function + get_function_callers + get_function_xrefs / get_xrefs_to + get_assembly_context + ead_memory + search_strings. **No** disassemble_bytes. **No** Launcher / runtime Confirmed.

### Live decompile (unchanged CF vs 2026-07-23 raw)

```c
undefined4 * __thiscall FUN_005ebec0(undefined4 *param_1,undefined4 param_2)

{
  FUN_005eb210(param_2);
  *param_1 = &PTR_FUN_009dce90;
  param_1[0x30] = 0;
  param_1[0x31] = 0;
  param_1[0x32] = 0x80000000;
  return param_1;
}
```

### Body / bytes

| Item | Value |
|---|---|
| Entry | `0x005ebec0` |
| Last insn | `RET 4` @ `0x005ebeee` (bytes through `0x005ebef0`) |
| Inclusive range | `0x005ebec0`–`0x005ebef0` (**49 B** / `0x31`) |
| Pad | `CC` from `0x005ebef1` |
| Hex | `8B 44 24 04 56 50 8B F1 E8 43 F3 FF FF C7 06 90 CE 9D 00 33 C0 89 86 C0 00 00 00 89 86 C4 00 00 00 C7 86 C8 00 00 00 00 00 00 80 8B C6 5E C2 04 00` |

### Assembly (disassemble_function — not disassemble_bytes)

```text
005ebec0  MOV  EAX, dword ptr [ESP+0x4]   ; stack arg = shape/params*
005ebec4  PUSH ESI
005ebec5  PUSH EAX
005ebec6  MOV  ESI, ECX                   ; this = query object*
005ebec8  CALL 0x005eb210                 ; base ctor FUN_005eb210
005ebecd  MOV  dword ptr [ESI], 0x9dce90  ; derived vtbl PTR_FUN_009dce90
005ebed3  XOR  EAX, EAX
005ebed5  MOV  dword ptr [ESI+0xc0], EAX  ; collect buf begin = 0
005ebedb  MOV  dword ptr [ESI+0xc4], EAX  ; collect count = 0
005ebee1  MOV  dword ptr [ESI+0xc8], 0x80000000  ; capacity sentinel (empty MSVC-style)
005ebeeb  MOV  EAX, ESI                   ; return this
005ebeed  POP  ESI
005ebeee  RET  0x4                        ; thiscall, 1 stack arg
```

### ABI seal

| Item | Evidence |
|---|---|
| Convention | **thiscall**: **ECX** = this (query object); stack `params*`; **RET 4** |
| ESI frame | `PUSH ESI` / `MOV ESI,ECX` / restore / RET 4 |
| Return | **EAX** = this (`MOV EAX,ESI`) |
| Layout writes | vtbl@+0; collect triad @ **+0xC0 / +0xC4 / +0xC8** (0, 0, 0x80000000) |
| Alloc size (call sites) | **0xD0** bytes, pool tag **0x2C** via `DAT_00b05060` allocator vfunc+0x10 |

### Callees

| VA | Name | Role |
|---|---|---|
| `0x005eb210` | `FUN_005eb210` | base query-object ctor (vtbl `009dcde0` + internal vectors); **not dualled here** |

### Callers / xrefs (3 UNCONDITIONAL_CALL)

| Site | Enclosing | Role |
|---|---|---|
| `0x004ea770` | `FUN_004ea350` | **Sphere mode** of `CVOGPhysicsUtils::GetObjectsInArea` when `param_5 == 2`: after `FUN_006c7fa0` sphere-shape setup, alloc 0xD0, construct this, then `FUN_00560c90(this+0xC, …)` to collect hits |
| `0x005dd368` | `FUN_005dd080` | Sphere-branch when `*(obj+0xdd) != 0`: same `006c7fa0` + alloc 0xD0 + construct; store result at `obj+0xd0` |
| `0x005ebfcf` | factory near dtor cluster | Placement-style factory: alloc 0xD0/tag 0x2C, set size word @+4, `CALL 005ebec0`, RET |

### Call-site ABI samples

1. **`FUN_004ea350` @ `0x004ea75e`–`0x004ea770`:**  
   `PUSH 0xD0` / allocator; `MOV word [EAX+4],0xD0`; `LEA ECX,[ESP+…]` (this); `PUSH` shape/params; `CALL 0x005ebec0`; EBX=return this; later `LEA EAX,[EBX+0xC]` into collect helper.
2. **`FUN_005dd080` @ `0x005dd359`–`0x005dd368`:**  
   Same 0xD0 construct; `MOV [ESI+0xD0], EAX` stores constructed query.
3. **Factory @ `0x005ebfba`–`0x005ebfd4`:**  
   `PUSH 0x2C; PUSH 0xD0; CALL [allocator+0x10]`; `PUSH` params; `MOV ECX,EAX`; `CALL 0x005ebec0`; `RET`.

### Sibling evidence (not dualled)

| VA | Role |
|---|---|
| `0x005ebf00` | dtor: walks/releases collect buffer at +0xC0 triad, then base teardown |
| `0x005ebf70` | scalar-deleting dtor (flag &1 → free 0xD0/tag 0x2C) |
| `0x006c7fa0` | sphere-shape setup (MEGA-071; mode-2 peer) |
| `0x004ea350` | `GetObjectsInArea` (string `CVOGPhysicsUtils::GetObjectsInArea::aabb` @ `0x009ccbe8`) |
| String `sphere` @ `0x009ccf60` | nearby physics-utils string table |

### Semantics seal

- **Derived ctor** for a **0xD0** physics **sphere-query collect object**:
  1. Base-init via `FUN_005eb210(params)`.
  2. Install derived vtbl `PTR_FUN_009dce90`.
  3. Zero-init **result collect buffer** triad at `this+0xC0`.
- **Not** the sphere shape (that is `006c7fa0`).
- **Not** the area-query loop (parent `004ea350` / `005dd080` + `00560c90`).
- Scaffold `Named_CalleeOf_Named_VOG_DEBUG_STOP_005ebec0` is **wrong** (parent path may hit VOG_DEBUG_STOP on null physics; this VA is pure ctor).

### Name proposal

`VOGPhysics_SphereQueryCollect_Ctor_Inferred` (Ghidra `FUN_005ebec0`). Product class/method English open → `_Inferred`. Role sealed by GetObjectsInArea mode-2 + 0xD0 alloc + collect-buffer init + dtor peer.

### Live ≡ raw CF

**Yes** — decompile body byte-identical in CF to 2026-07-23 scaffold; only ABI/offsets/callers refined.

