# Raw capture: FUN_006c7fa0

| Field | Value |
|---|---|
| **Stable ID** | `aa_006c7fa0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x006c7fa0` |
| **Canonical name** | `FUN_006c7fa0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void __thiscall FUN_006c7fa0(undefined4 *param_1,undefined4 param_2)

{
  *(undefined2 *)((int)param_1 + 6) = 1;
  param_1[2] = 0;
  param_1[3] = param_2;
  *param_1 = &PTR_FUN_00a0d610;
  return;
}
```

---

## MEGA-071 re-verify append (2026-08-05)

**Agent:** OWN-ONLY dual **MEGA-071**  
**Tools:** Ghidra `decompile_function` + `analyze_function_complete` + `disassemble_function` + `read_memory` + `get_function_callers` + `get_function_xrefs` + `get_assembly_context`. **No** `disassemble_bytes`. No Launcher.  
**Partition:** `docs/reconstruction/reviews/WAVE_2026-08-05_mega_residual_partition_map.md` → **MEGA-071** (sphere-shape setup mode-2).

### Live decompile (2026-08-05) — identical CF to scaffold

```c
void __thiscall FUN_006c7fa0(undefined4 *param_1,undefined4 param_2)

{
  *(undefined2 *)((int)param_1 + 6) = 1;
  param_1[2] = 0;
  param_1[3] = param_2;
  *param_1 = &PTR_FUN_00a0d610;
  return;
}
```

### Body bytes (`read_memory` @ `0x006c7fa0`, 32 B)

```text
8b c1                 MOV EAX, ECX
8b 4c 24 04           MOV ECX, dword ptr [ESP+0x4]
66 c7 40 06 01 00     MOV word ptr [EAX+0x6], 0x1
c7 40 08 00 00 00 00  MOV dword ptr [EAX+0x8], 0x0
89 48 0c              MOV dword ptr [EAX+0xc], ECX
c7 00 10 d6 a0 00     MOV dword ptr [EAX], 0x00a0d610
c2 04 00              RET 0x4
cc                    INT3 pad
```

**Body:** `0x006c7fa0`–`0x006c7fbe` exclusive end after `RET 0x4` (**29 B** / `0x1D`); `CC` pad @ `0x006c7fbd`.

### `disassemble_function` (matches hex)

```text
006c7fa0: MOV EAX,ECX
006c7fa2: MOV ECX,dword ptr [ESP + 0x4]
006c7fa6: MOV word ptr [EAX + 0x6],0x1
006c7fac: MOV dword ptr [EAX + 0x8],0x0
006c7fb3: MOV dword ptr [EAX + 0xc],ECX
006c7fb6: MOV dword ptr [EAX],0xa0d610
006c7fbc: RET 0x4
```

### ABI (sealed)

| Slot | Value | Evidence |
|---|---|---|
| Convention | **`__thiscall`** | `MOV EAX,ECX` then stack arg |
| this (shape*) | **ECX** → saved EAX | entry |
| stack arg | radius / scalar @ `[ESP+4]` | `MOV ECX,[ESP+4]` then store @ `+0xc` |
| Return | **EAX = this** | EAX preserved as object |
| Cleanup | **`RET 4`** | terminal `C2 04 00` |
| Callees | **none** (leaf) | analyze `callees:[]` |

### Object layout after init (size **0x10**)

| Offset | Write | Meaning (inferred) |
|---|---|---|
| +0x00 | `PTR_FUN_00a0d610` | vtbl install |
| +0x04 | *(not written here)* | parent sets u16 size tag `0x10` pre-call |
| +0x06 | `u16 = 1` | refcount |
| +0x08 | `u32 = 0` | clear field |
| +0x0c | stack arg | **radius float** (parent mode-2 passes `param_3`) |

### Vtbl `PTR_FUN_00a0d610` (`read_memory` 64 B)

```text
[0]  006c6490  dtor/release (refcount path)
[1]  005ffd80
[2]  005ffdb0
[3]  006ce4e0
[4]  005ffc80
[5]  00668190
[6]  006c7f20  getAabb: expand object AABB by radius@+0xc
[7]  006c7c30  support / max projection + radius@+0xc
[8]  006c7fc0  ray vs sphere (radius^2 @ +0xc; quadratic)
[9]  006c7c70
[10] 006c7e90
[11] 006c7f80
[12] 006c7eb0
[13] 006c7ed0
[14] 006c7f00
[15] 0066b6f0
```

Sphere role sealed by vtbl methods using `*(float*)(this+0xc)` as radius (AABB inflate, support, raycast).

### Callers / xrefs (live)

**Callers (17):**  
`FUN_004e9720`, `FUN_004e9aa0`, `FUN_004ea350`, `FUN_004ed470`, `FUN_004ee080`, `FUN_005dd080`, `FUN_005f1ec0`, `FUN_005f3e10`, `FUN_006ca1d0`, `FUN_006ec530`, `FUN_006ec690`, `FUN_006ec7f0`, `FUN_006ec970`, `FUN_006ecad0`, `FUN_006ecc50`, `FUN_006ecdb0`, `FUN_006ed0d0`

**Xrefs (18 UNCONDITIONAL_CALL):**  
`004e976e`, `004ea07d`, `004ea6ce`, `004edfb6`, `004ee322`, `004ee93d`, `005dd2b7`, `005f232c`, `005f3e5d`, `006ca71e`, `006ec55d`, `006ec6bd`, `006ec81b`, `006ec999`, `006ecafb`, `006ecc7d`, `006ecddb`, `006ed137`

### Representative call-site (mode-2 of dualed `CVOGPhysicsUtils_GetObjectsInArea` @ `0x004ea6ce`)

```text
// allocator: (*DAT_00b05060+0x10)(0x10, 0x22) → size 0x10, pool/type 0x22
MOV word ptr [EAX+0x4], 0x10
PUSH radius                 // parent param_3 (float)
MOV ECX, EAX                // this = shape buffer
CALL 0x006c7fa0
// then FUN_005eb8d0 / center copy / FUN_005ebec0 collector
```

Same pre-call pattern at `004e976e`, `005f3e5d`: alloc 0x10/0x22, tag `+4=0x10`, push radius, thiscall.

### Classification

| Item | Value |
|---|---|
| analyze classification | leaf |
| Semantics | **Sphere shape ctor / setup from radius** |
| System (partition) | interaction-activation |
| Parent evidence | dualed `CVOGPhysicsUtils_GetObjectsInArea` mode `param_5==2` |
| Prior scaffold name | `Named_CalleeOf_Named_VOG_DEBUG_STOP_006c7fa0` — **retired** (VOG_DEBUG_STOP is AABB-fail sibling path, not this callee) |
| Promoted name | `PhysicsShape_Sphere_CtorFromRadius_Inferred` |

### Gaps (re-verify)

- Product / PDB demangle for shape class (no RTTI string in body).
- Exact English for field @+0x08 (cleared 0; unused by ctor).
- Runtime / bit-exact / differential open.
