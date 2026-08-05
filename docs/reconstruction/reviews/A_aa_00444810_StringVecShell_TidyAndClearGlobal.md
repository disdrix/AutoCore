# Review A (reconstruction fidelity): `aa_00444810` StringVecShell_TidyAndClearGlobal

| Field | Value |
|---|---|
| **Stable ID** | `aa_00444810` |
| **VA** | `0x00444810`–`0x0044484A` exclusive (**58 B**) |
| **Canonical name** | `StringVecShell_TidyAndClearGlobal` |
| **Ghidra name** | `FUN_00444810` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY W34-K) |
| **Counterpart** | `reviews/B_aa_00444810_StringVecShell_TidyAndClearGlobal.md` |
| **System** | Palantir path-list shell tidy + `DAT_00d1f1fc` clear |
| **Evidence pass** | Live Ghidra `decompile_function` + `analyze_function_complete` + `read_memory` (full body 58 B) + SEH site bytes `@009afd00`. **No** `disassemble_bytes`. |
| **Verdict** | **accept** |

---

## 1. Purpose

Fully tidy a `StringVecShell` (via sealed `StringVec_Tidy`) and null the published global path-list pointer `DAT_00d1f1fc`. Shared MSVC SEH helper for Palantir complete-dtor unwind when the shell is at `host+0xA0`.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw (+ W34-K append) | `docs/reconstruction/raw/aa_00444810_FUN_00444810.md` |
| Annotated | `docs/reconstruction/raw/aa_00444810_FUN_00444810.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StringVecShell_TidyAndClearGlobal.cpp` |
| Scaffold twin | `docs/reconstruction/reconstructed-exact/FUN_00444810.cpp` |
| Function records | `functions/aa_00444810_FUN_00444810.md`, `functions/aa_00444810_StringVecShell_TidyAndClearGlobal.md` |
| Nested tidy | `StringVec_Tidy` (`0x00431ae0`, W33-D sealed) |
| Live | decompile + 58 B hex + unwind site memory |

---

## 3. Signature (sealed)

```c
// ECX=shell; bare RET; void
void StringVecShell_TidyAndClearGlobal(StringVecShell* shell);
```

| Formal | Source | Conf |
|---|---|---|
| shell | ECX (set by SEH: `host+0xA0`; preserved through SEH prolog) | **High** |
| cleanup | `C3` | **High** |
| stack args | none | **High** |

---

## 4. Control flow (bytes authority)

```
// SEH frame LAB_009bd525
StringVec_Tidy(ECX)     // CALL 0x00431ae0
DAT_00d1f1fc = 0
unlink SEH; ADD ESP,0xC; RET
```

| Stage | Match | Conf |
|---|---|---|
| ECX preserved into tidy | prolog uses EAX/ESP only | **High** |
| tidy then global null | call then `C7 05 FC F1 D1 00 …` | **High** |
| bare RET | `C3` after `83 C4 0C` | **High** |
| SEH-only callers | xrefs → Unwind only | **High** |

---

## 5. Machine bytes (`read_memory`)

Full body hex (58 B) — see raw W34-K append.

Entry: `64 A1 00 00 00 00 6A FF 68 25 D5 9B 00 …`  
Epilogue: `64 89 0D 00 00 00 00 83 C4 0C C3`  
Pad: `CC` from `0x0044484A`; next `FUN_00444850` @ `0x00444850`.

**Decompile ≢ bytes:** void / no formal; omits ECX contract. **Bytes + SEH sites win.**

---

## 6. Callers / classification

| Item | Value |
|---|---|
| Classification | worker |
| Callers | `Unwind@009afd09`, `Unwind@009afd4a` (Palantir dtor SEH) |
| Callees | `StringVec_Tidy` (`0x00431ae0`) |

---

## 7. Gaps

1. Product English for path-list role (naming-only).  
2. Runtime / bit-exact / differential.

---

## 8. Verdict

58 B body fully sealed: ECX shell, tidy, global clear, SEH-only Palantir unwind callers → **accept**.
