# Review A (reconstruction fidelity): `aa_00763f60` GfxBody_CompleteDtor_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00763f60` |
| **VA** | `0x00763f60`–`0x0076402d` (**206 B**) |
| **Canonical name** | `GfxBody_CompleteDtor_Inferred` |
| **Ghidra name** | `FUN_00763f60` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY W31-C) |
| **Counterpart** | `reviews/B_aa_00763f60_GfxBody_CompleteDtor_Inferred.md` |
| **System** | graphics-body composite complete dtor |
| **Evidence pass** | Live Ghidra `batch_decompile` / `decompile_function` + `analyze_function_complete` + `read_memory` (full body hex) + xrefs. **No** `disassemble_bytes`. |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Complete destructor for graphics-body class `PTR_LAB_00a9da8c`: set vtbl, nested teardown, free subobject vector / ptr-vector / two buffer triples / aligned host, base dtor. Does not free `this`.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw (+ W31-C append) | `docs/reconstruction/raw/aa_00763f60_FUN_00763f60.md` |
| Annotated | `docs/reconstruction/raw/aa_00763f60_FUN_00763f60.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/GfxBody_CompleteDtor_Inferred.cpp` |
| Twin | `docs/reconstruction/reconstructed-exact/FUN_00763f60.cpp` |
| Function record | `docs/reconstruction/functions/aa_00763f60_GfxBody_CompleteDtor_Inferred.md` |
| Consumer | `aa_004be2a0` ListTrackedObj_CompleteDtor (W30-P) ×3 members |
| Peer ctor | `FUN_00764030` (same vtbl) |
| Live | decompile stage order ≡ bytes; epilogue hex seals fall-through past false noreturn |

---

## 3. Signature (sealed)

```c
// ECX = this; SEH LAB_009b0ac6; ADD ESP,0x10; C3; void
void __fastcall GfxBody_CompleteDtor_Inferred(void* self);
```

| Formal | Source | Conf |
|---|---|---|
| self | ECX (`8B F1`) | **High** |
| return | void (no free this) | **High** |
| cleanup | `83 C4 10 C3` | **High** |

---

## 4. Control flow (bytes authority)

```
SEH prolog; ESI=this; *this = PTR_LAB_00a9da8c; EH=5
FUN_00763740(this)
EH=4; EBX=this+0x128; FUN_004380f0()
EH=3; FUN_00968110(this+0xDC)
if buf@+0xD0: operator_delete; zero +0xD0/+0xD4/+0xD8
if buf@+0xC0: operator_delete; zero +0xC0/+0xC4/+0xC8
EH=0; FUN_0096aec0(this+0x98)
EH=-1; FUN_0096d7a0(this)
SEH restore; ADD ESP,0x10; RET
```

| Stage | Match | Conf |
|---|---|---|
| Vtbl install `8C DA A9 00` | decompile ≡ `C7 06 …` | **High** |
| LEA offsets +0x128/+0xDC/+0x98 | decompile ≡ bytes | **High** |
| Buffer triples zero | decompile ≡ stores | **High** |
| Reaches RET | full 206 B hex | **High** |

---

## 5. Machine bytes (`read_memory`)

Full body hex (206 B) — see raw W31-C append.  
Entry SEH: `6A FF 68 C6 0A 9B 00 64 A1 …`.  
Epilogue: `… 83 C4 10 C3` then `CC`.

---

## 6. Callers / classification

| Item | Value |
|---|---|
| Classification | worker (complete dtor body) |
| Callers | `FUN_004be2a0` ×3, graphics/load sites, SEH unwinds |
| Pattern | member complete dtor; outer owner frees separately when heap-owned |

---

## 7. Gaps

1. Product/MSVC demangle for class (`00a9da8c`).  
2. Nested `FUN_00763740` / `FUN_004380f0` / base `FUN_0096d7a0` product English.  
3. Exact object size (ctor zeroes through ~0x148; embed stride 0x14C).  
4. Runtime / bit-exact / differential — open.

---

## 8. Verdict

Complete-dtor role, ABI/SEH, vtbl, offsets, and epilogue sealed. Residual product class + nested callees → **accept-with-gaps**.
