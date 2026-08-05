# Review A (reconstruction fidelity): `aa_00725a70` CSoundManager_TryQueueMissionCompleteSound_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00725a70` |
| **VA** | `0x00725a70`–`0x00725bcd` (349 bytes) |
| **Canonical name** | `CSoundManager_TryQueueMissionCompleteSound_Inferred` |
| **Ghidra symbol** | `FUN_00725a70` |
| **Review date** | `2026-07-29` (W18-R dual A/B seal) |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_00725a70_CSoundManager_TryQueueMissionCompleteSound_Inferred.md` |
| **System** | client audio / `CSoundManager` / mission-complete SFX |
| **Verdict** | **accept-with-gaps** |

**Tools:** Ghidra `decompile_function` + `read_memory` only (no `disassemble_bytes`). Sibling cross-check: `0x007258a0` TryQueueProximitySound.

---

## 1. Purpose

**`__thiscall`** on `CSoundManager`: resolve a sound path and queue a **hardcoded type-0x32** play slot if the manager is enabled and the world position is **zero-length** or within a **fixed XZ radius** (dist² ≤ 10000). Returns **1/0**.

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_00725a70_FUN_00725a70.md` |
| Annotated | `docs/reconstruction/raw/aa_00725a70_FUN_00725a70.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/CSoundManager_TryQueueMissionCompleteSound_Inferred.cpp` |
| Scaffold | `docs/reconstruction/reconstructed-exact/FUN_00725a70.cpp` |
| Function record | `docs/reconstruction/functions/aa_00725a70_CSoundManager_TryQueueMissionCompleteSound_Inferred.md` |
| Sibling dual | `A_aa_007258a0_CSoundManager_TryQueueProximitySound_Inferred.md` |

---

## 3. Confidence table

| Claim | Confidence | Evidence |
|---|---|---|
| thiscall; this in EBP; `ret 8` | **High** | prologue `mov ebp,ecx`; epilogue bytes |
| Enable `this+0x258` | **High** | early cmp/return 0 |
| XZ-only fixed radius dist² ≤ 10000 | **High** | `+0x220/+0x228` vs pos x/z; `DAT_00aaa880=10000.0f` |
| Zero-length pos always in | **High** | first arm of compound if |
| No type 0xC/0xD busy gate | **High** | absent vs sibling |
| Resolve via `FUN_007249c0` | **High** | call + sibling |
| Slot type `0x32`, TFID `-1` | **High** | `read_memory` dword stores |
| `+0x110=20`, `+0x114=100`, `+0x11c=1` | **High** | float constants sealed |
| Decompiler `g_nInferredThreatDefault` wrong | **High** | bytes load `DAT_00aaa6e8` float |
| Queue `FUN_00480350(this+0x310)` | **High** | call + sibling |
| Mission-complete role | **High** | sole xref `FUN_004b0f80` + `Client_GetMissionCompleteAudioTable` |
| Product English name | **Inferred** | structural + caller |
| Null-slot strncpy safety | **Medium** residual | decompiler path |

---

## 4. Control flow: clean ≡ raw ≡ bytes

| Stage | Match |
|---|---|
| Enable gate | **Yes** |
| Fixed proximity gate | **Yes** |
| Resolve / freelist / init | **Yes** |
| Hardcoded field patch | **Yes** (clean uses float seals) |
| List push + return 1/0 | **Yes** |

---

## 5. Gaps / open

1. Product/PDB English confirmation.
2. Freelist-null strncpy UB residual.
3. Runtime / bit-exact / differential — open.

**Verdict:** **accept-with-gaps**
