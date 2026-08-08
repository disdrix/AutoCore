# Review A (reconstruction fidelity): `aa_007a8580` CNDUIWindow_ClearOwnedObject_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_007a8580` |
| **VA** | `0x007a8580`–`0x007a85df` (**96 B** / `0x60`) |
| **Canonical name** | `CNDUIWindow_ClearOwnedObject_Inferred` |
| **Ghidra name** | `FUN_007a8580` |
| **Review date** | `2026-08-05` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY WQ9L-E) |
| **Counterpart** | `reviews/B_aa_007a8580_CNDUIWindow_ClearOwnedObject_Inferred.md` |
| **System** | CNDUIWindow / UI owned-object clear |
| **Evidence pass** | Live Ghidra `batch_decompile` + `analyze_function_complete` + `disassemble_function` + `read_memory` + callers/xrefs + owner vtbl/RTTI. **No** `disassemble_bytes`. |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Virtual **clear** of CNDUIWindow-family owned object slot at `this+0x298`: optional child release at `+0x2B4` (flags=0), vtbl refresh/string-clear, conditional scalar-delete when ownership flag `+0xBC` set, always null `+0x298`.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw (+ WQ9L-E append) | `docs/reconstruction/raw/aa_007a8580_FUN_007a8580.md` |
| Annotated | `docs/reconstruction/raw/aa_007a8580_FUN_007a8580.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/CNDUIWindow_ClearOwnedObject_Inferred.cpp` |
| Twin | `docs/reconstruction/reconstructed-exact/FUN_007a8580.cpp` |
| Parent complete | `CNDUIWindow_CompleteDtor` (calls this early in free chain) |
| Set pair | `FUN_007a85e0` (vtbl +0x40 → calls vtbl +0x44) |

---

## 3. Signature (sealed)

```c
// ECX = this; bare RET (C3); void
void __fastcall CNDUIWindow_ClearOwnedObject_Inferred(void* self);
```

| Formal | Source | Conf |
|---|---|---|
| self | ECX (`8B F1`) | **High** |
| return | void | **High** |
| cleanup | bare `C3` | **High** |

---

## 4. Control flow (bytes authority)

| Stage | Match | Conf |
|---|---|---|
| Guard `+0x298 != 0` | `CMP [ESI+0x298],EBX` / `JZ` | **High** |
| Child `+0x2B4` dtor flags=0 | `PUSH EBX; CALL [EAX]` | **High** |
| vcall `+0x4C` | `CALL [EDX+0x4C]` | **High** |
| vcall `+0x288` empty string | `PUSH 0xa1419b; CALL [EAX+0x288]` | **High** |
| Own flag `+0xBC` → delete flags=1 | `CMP [ESI+0xBC]; PUSH 1; CALL` | **High** |
| Always null `+0x298` | final `MOV [ESI+0x298],EBX` | **High** |
| Reaches RET | epilogue `5E 5B C3` | **High** |

---

## 5. Machine bytes

Full 96 B hex in raw WQ9L-E append. Entry: `53 56 8B F1 33 DB 39 9E 98 02 00 00 …`. Epilogue: `89 9E 98 02 00 00 5E 5B C3`.

---

## 6. Callers / classification

| Item | Value |
|---|---|
| Classification | worker virtual method (vtbl +0x44) |
| Code callers | `CNDUIWindow_CompleteDtor`, `FUN_0078ca80` (buffered complete) |
| DATA xrefs | many derived UI vtbls |
| Set pair | `FUN_007a85e0` @ vtbl +0x40 |

---

## 7. Gaps

1. Product English for object type at `+0x298`.  
2. Product names for vtbl `+0x4C` / `+0x288`.  
3. Runtime / bit-exact / differential — open.

---

## 8. Verdict

CF/ABI/offsets/vtbl slot/set-pair/call-site role sealed. Product residual on owned-object type → **accept-with-gaps**.
