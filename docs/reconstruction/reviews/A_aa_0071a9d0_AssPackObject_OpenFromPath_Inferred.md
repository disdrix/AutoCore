# Review A (reconstruction fidelity): `aa_0071a9d0` AssPackObject_OpenFromPath_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0071a9d0` |
| **VA** | `0x0071a9d0`–`0x0071aae4` (**277 B**) |
| **Canonical name** | `AssPackObject_OpenFromPath_Inferred` |
| **Ghidra name** | `FUN_0071a9d0` |
| **Review date** | `2026-08-04` (W37-X dual seal) |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY W37-X) |
| **Counterpart** | `reviews/B_aa_0071a9d0_AssPackObject_OpenFromPath_Inferred.md` |
| **System** | palantir assets / assPackManager |
| **Evidence pass** | Live Ghidra decompile + `read_memory` (277 B) + `analyze_function_complete` + sole-caller assembly context + string `"glm"` @ `0x00aa61bc` |
| **Verdict** | **accept-with-gaps** |

**Tools:** decompile + read_memory (+ analyze/callers/xrefs). **No** `disassemble_bytes`. No Launcher.

---

## 1. Purpose

Open a pre-constructed **0x44 pack object** from a path: own a strdup path, ensure/build path with **`glm`** token, open underlying OS file(s) via `FUN_007669d0`, then size/seek/read a 4-byte footer and parse via `FUN_0071a4a0`.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw | `docs/reconstruction/raw/aa_0071a9d0_FUN_0071a9d0.md` (+ W37-X full hex) |
| Annotated | `docs/reconstruction/raw/aa_0071a9d0_FUN_0071a9d0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/AssPackObject_OpenFromPath_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0071a9d0.cpp` |
| Function records | `aa_0071a9d0_FUN_0071a9d0.md`, `…_AssPackObject_OpenFromPath_Inferred.md` |
| Live | 277 B hex; `RET 4`; `MOV ESI,EAX`; `MOV [EDI+0x28]`; `LEA ECX,[EDI+0x14]` second open |
| Caller | `FUN_00984ee0` @ `0x00984f66` — product assPackManager.cpp plate (W31-H dual) |

---

## 3. Signature (sealed)

```c
// EAX=path, EDI=pack, stack=AssPackManager*, RET 4
int AssPackObject_OpenFromPath_Inferred(/*regs+stack*/);
```

| Slot | Source | Conf |
|---|---|---|
| path | EAX | **High** |
| pack | EDI | **High** |
| owner | stack (PUSH EBX) | **High** |
| return | 0 / parse / −1 | **High** |

---

## 4. Control flow (clean ≡ raw ≡ bytes)

| Stage | Match | Conf |
|---|---|---|
| strdup → pack+0x28 | **Yes** | **High** |
| `"glm"` via FUN_0076b190 | **Yes** (`MOV ESI,0x00aa61bc`) | **High** |
| mode 1 vs 3 from pack+0x40 | **Yes** | **High** |
| stat + bit15 regular-file gate | **Yes** | **High** |
| dual open pack / pack+0x14 | **Yes** (`LEA ECX,[EDI+0x14]`) | **High** |
| else mode-6 open | **Yes** | **High** |
| vcall size / seek / read4 / parse | **Yes** | **High** |
| FUN_0071a4a0 full contract | open (unowned) | **Medium** |
| Product pack class English | open | **Low** |

---

## 5. Gaps / open

1. Product English for 0x44 pack class (beyond caller plate).
2. Exact CreateFile access/disposition map for modes 1/3/6 (`FUN_007669d0` / W37-E).
3. Full `FUN_0071a4a0` TOC/parse semantics and exact arg binding of stack owner vs footer.
4. Runtime / bit-exact / differential.

**Verdict:** **accept-with-gaps** — ABI + open policy + dual-file + footer handoff sealed; parse helper and product pack type residual.
