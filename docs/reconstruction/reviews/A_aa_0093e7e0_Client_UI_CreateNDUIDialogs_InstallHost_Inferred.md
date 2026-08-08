# Review A (reconstruction fidelity): `aa_0093e7e0` Client_UI_CreateNDUIDialogs_InstallHost_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0093e7e0` |
| **VA** | `0x0093e7e0`–`0x0093ffa3` inclusive (**6084 B** / `0x17C4`) |
| **Canonical name** | `Client_UI_CreateNDUIDialogs_InstallHost_Inferred` |
| **Ghidra name** | `FUN_0093e7e0` |
| **Prior scaffolds** | `Named_CalleeOf_Mission_createNDUIDialogs_0093e7e0`; mis-alias `Combat_DeathRespawnButton` |
| **Review date** | `2026-08-05` (MEGA-133 OWN dual) |
| **Reviewer role** | Reconstruction fidelity / evidence-only naming |
| **Counterpart** | `reviews/B_aa_0093e7e0_Client_UI_CreateNDUIDialogs_InstallHost_Inferred.md` |
| **System** | missions-progression / client UI init (NDUI dialog host install) |
| **Verdict** | **accept-with-gaps** |

**Tools:** Ghidra `decompile_function` + `disassemble_function` + `get_function_callers` + `get_function_callees` + `get_function_xrefs` + `get_function_by_address` + `get_function_signature` + `read_memory` + caller decompile `0x0094a580`. **No** `disassemble_bytes`. No Launcher.

---

## 1. Purpose

Bulk **CreateNDUIDialogs** installer: allocate/construct NDUI dialogs and related chrome, store pointers on the client UI host, apply post-install flags and `winpos.ini` layout, and emit phase timing via `OutputDebugStringA`.

```text
Client_UI_CreateNDUIDialogs_InstallHost_Inferred(host)  // stdcall RET 4
  SEH + timing "@@CreateNDUIDialogs"
  cursor host+0x1168: load i_g_2d_cursor.xml; rebind +0x88
  for many phases:
    operator_new(size) → dialog_ctor → host.slot = ptr  (or DAT_00d09a**)
    optional vtbl init (+0x28 XML / +0x43c / +0xcc / +0x300 / +0x74)
  post: 0x3a × vtbl+0x174 on host+0x1030 table
  post: 0x1d pairs set dialog+0xc6 = 1; host+0x1100 forced 0
  FUN_00931570(host) with "winpos.ini"
  QPC delta → sprintf("(%f) %s\n") → OutputDebugStringA
  return
```

Sole caller is `FUN_0094a580` (InitUserInterface / `Mission_createNDUIDialogs` wrapper) after log `"createNDUIDialogs"`.

---

## 2. Inspected artifacts

| Artifact | Source |
|---|---|
| Live decompile | ≡ raw CF 2026-07-23 (install ladder + post loops + timing) |
| Full body bounds | `get_function_by_address` `0093e7e0`–`0093ffa3`; `disassemble_function` epilogue `RET 4` |
| Callers/xrefs | **1** UNCONDITIONAL_CALL @ `0x0094a649` from `FUN_0094a580` |
| Callees | 90+ FUN_* + `operator_new` + QPC/`sprintf`/`OutputDebugStringA` |
| Plate/XML strings | `read_memory` of PUSH immediates (`@@CreateNDUIDialogs`, cursor/death/tooltip XML, HUD/info phases, `winpos.ini`) |
| Parent context | decompile `FUN_0094a580`: `"InitUserInterface start"` → … → `"createNDUIDialogs"` → **this** |
| Dualed helper | `CNDHash_Ctor_00a2c2b0` (`FUN_004063a0`) used for `host+0x3084` |

---

## 3. Signature (sealed)

```c
// stack host*; EBP = host for body; void; RET 4
void __stdcall Client_UI_CreateNDUIDialogs_InstallHost_Inferred(ClientUiHost* host);
```

| Formal | Source | Conf |
|---|---|---|
| host | stack arg0 → `MOV EBP,[ESP+0x484]` after frame | **Confirmed** |
| thiscall ECX | not used as host on entry | **Confirmed** (falsified) |
| return | void | **Confirmed** |
| cleanup | `RET 4` (`C2 04 00`) @ `0x0093ffa1` | **Confirmed** |
| parent pass | `FUN_0093e7e0(unaff_ESI)` | **Confirmed** |

---

## 4. Control flow (sealed)

| Stage | Match | Conf |
|---|---|---|
| SEH install FS:[0] / `LAB_009bb29b` | bytes | **Confirmed** |
| Timing plates via `FUN_007a4400` / `FUN_007a4390` | decompile + string PUSH | **Confirmed** |
| Cursor load + rebind `+0x1168` | CF + `i_g_2d_cursor.xml` | **Confirmed** |
| Mass `operator_new` + ctor + host store | decompile ladder | **Confirmed** |
| Death-respawn XML + id `0x4e5d` | decompile site `host+0x1158` | **Confirmed** |
| Post loop 0x3a × vtbl+0x174 | decompile + asm | **Confirmed** |
| Post loop flags `+0xc6` + special `+0x1100` | decompile | **Confirmed** |
| `FUN_00931570` + `winpos.ini` | asm `MOV EAX,0xa2d3d4; MOV ECX,EBP; CALL` | **Confirmed** |
| QPC timing `OutputDebugStringA` | epilogue | **Confirmed** |
| Live decompile ≡ raw body | byte-identical CF | **Confirmed** |

---

## 5. Callers / classification

| Item | Value |
|---|---|
| Classification | client UI **init worker** (not free entry; not single-widget) |
| External callers | **1** (`FUN_0094a580`) |
| Site role | body of createNDUIDialogs after parent log line |
| Callees | many dialog ctors; CNDHash; timing; winpos apply; CRT/Win32 |
| Globals written | `DAT_00d09a38`..`DAT_00d09a48` |

---

## 6. Naming gate

| Evidence | Present? |
|---|---|
| Plate `@@CreateNDUIDialogs` | **Yes** |
| Parent log `"createNDUIDialogs"` then call | **Yes** |
| Multi-dialog host install CF | **Yes** |
| Single death-respawn-only purpose | **No** (reject Combat_* misname) |
| PDB / demangled product symbol | **No** → `_Inferred` |

**Decision:** promote **`Client_UI_CreateNDUIDialogs_InstallHost_Inferred`**. Retire Named_CalleeOf_ scaffold and Combat_DeathRespawnButton alias.

---

## 7. Gaps

- Per-slot product dialog class English (HUD / arena / info / inventory, …).
- Vtbl method dictionary for NDUI base class.
- Full catalog of ctor callees dualed separately.
- Runtime Confirmed / bit-exact / differential.
- Parent `FUN_0094a580` residual (out of OWN scope).

---

## 8. Verdict

Fidelity path seals CF, ABI (`__stdcall` RET 4), sole caller, phase plates, and install/post-layout role. Product-level dialog catalog and vtbl English remain open → **accept-with-gaps**.
