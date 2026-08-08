# Review A (reconstruction fidelity): `aa_00423e50` CNDUIWindow_ScalarDeletingDtor

| Field | Value |
|---|---|
| **Stable ID** | `aa_00423e50` |
| **VA** | `0x00423e50`–`0x00423e6d` inclusive (**30 B** / `0x1E`) |
| **Canonical name** | `CNDUIWindow_ScalarDeletingDtor` |
| **Ghidra name** | `FUN_00423e50` |
| **Review date** | `2026-08-05` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY MEGA-139) |
| **Counterpart** | `reviews/B_aa_00423e50_CNDUIWindow_ScalarDeletingDtor.md` |
| **System** | skills-abilities residual partition / UI CNDUIWindow scalar-deleting dtor / `PTR_FUN_00a960ac` |
| **Evidence pass** | Live Ghidra `decompile_function` + `analyze_function_complete` + `disassemble_function` + `get_function_xrefs` / callers / callees + multi-span `read_memory` (body, vtbl, RTTI). **No** `disassemble_bytes`. |
| **Verdict** | **accept** |

---

## 1. Purpose

MSVC scalar-deleting destructor (`vtbl[0]`): always run complete dtor `FUN_007b5be0` / `CNDUIWindow_CompleteDtor`; if `(flags & 1)` free the host with `operator_delete`; return `this`.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw (+ MEGA-139 append) | `docs/reconstruction/raw/aa_00423e50_FUN_00423e50.md` |
| Annotated | `docs/reconstruction/raw/aa_00423e50_FUN_00423e50.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/CNDUIWindow_ScalarDeletingDtor.cpp` |
| Scaffold twin | `docs/reconstruction/reconstructed-exact/FUN_00423e50.cpp` |
| Function records | `aa_00423e50_FUN_00423e50.md`, `aa_00423e50_CNDUIWindow_ScalarDeletingDtor.md` |
| Parent complete | dualed `aa_007b5be0` `CNDUIWindow_CompleteDtor` (WQ9K-F) |
| Live | decompile ≡ bytes CF; vtbl dword @ `0x00a960ac` = `0x00423e50`; RTTI `.?AVCNDUIWindow@@` |
| Peer pattern | `InventoryGrid_ScalarDeletingDtor` / other MSVC scalar thunks (same 30 B shape) |

---

## 3. Signature (sealed)

```c
// ECX=this; stack flags; RET 4; returns this*
void* __thiscall CNDUIWindow_ScalarDeletingDtor(void* self, uint8_t flags);
```

| Formal | Source | Conf |
|---|---|---|
| self | ECX (`56 8B F1`) | **High** |
| flags | stack (`F6 44 24 08 01`) | **High** |
| return | EAX = ESI = this | **High** |
| cleanup | `C2 04 00` | **High** |

---

## 4. Control flow (bytes authority)

```
ESI = this
call FUN_007b5be0              // complete dtor
if (flags & 1):
  operator_delete(this)        // + ADD ESP,4
return this                    // RET 4
```

| Stage | Match | Conf |
|---|---|---|
| Complete-then-optional-free | decompile ≡ 30 B hex | **High** |
| bit0 gate only (not vector) | `test …,1` / `jz` | **High** |
| False noreturn ignored | epilogue after delete + `ADD ESP,4` in hex | **High** |
| vtbl[0] | DATA `00a960ac` → `00423e50` | **High** |
| CNDUIWindow family | RTTI + complete/ctor install same vtbl | **High** |

---

## 5. Machine bytes (`read_memory`)

Full body hex (30 B):

```
568bf1e8881d3900f644240801740956e8bd59060083c4048bc65ec20400
```

Pad `CC CC` at `0x00423e6e`.  
Note: `disassemble_function` listing omits `ADD ESP,4` @ `00423e65` under false-noreturn on `operator_delete`; bytes seal it.

---

## 6. Callers / classification

| Item | Value |
|---|---|
| Classification | worker (`analyze_function_complete`) |
| Callers | DATA vtbl[0] only (no bulk code CALL sites); virtual from `delete CNDUIWindow*` / slot-0 dispatch |
| Callees | `FUN_007b5be0` @ `0x007b5be0`, `operator_delete` @ `0x00489822` |
| Vtbl install | complete @ `0x007b5c00`; ctor twin `FUN_007b5dd0` @ `0x007b5dfc` |

---

## 7. Gaps

1. Runtime / bit-exact / differential — open (no Launcher; Terminal false).  
2. Complete dtor member map not owned here (`FUN_007b5be0`, dualed parent).  
3. Product MSVC demangle for the scalar thunk symbol itself (naming only; class sealed).

---

## 8. Verdict

ABI, CF, vtbl slot, scalar-vs-complete separation, and CNDUIWindow RTTI family link are sealed with high confidence. Residual gaps are runtime / parent-member English only → **accept**.
