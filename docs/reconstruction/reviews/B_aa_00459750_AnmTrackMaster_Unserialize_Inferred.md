# Review B (skeptical / adversarial): `aa_00459750` AnmTrackMaster_Unserialize_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00459750` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (OWN-ONLY W36-M) |
| **Counterpart** | `reviews/A_aa_00459750_AnmTrackMaster_Unserialize_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

**Tools:** Ghidra `batch_decompile` + `read_memory` + xrefs only. **No** `disassemble_bytes`.

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | cdecl / no stack cleanup | **Falsified** — epilog `C2 04 00` (`RET 4`) |
| 2 | Not thiscall | **Falsified** — `MOV EBX,ECX` at entry; this used throughout |
| 3 | Tags are MBAP/KART product names as LE strings | **Nuance** — host u32 `0x5042414D`/`0x5452414B` = file bytes MABP/KART = fourCC names **PBAM**/**TRAK** (same convention as EFCT/TRAK writers) |
| 4 | This is a generic STL helper | **Falsified** — chunk scope, path log, dual I/O, domain fields |
| 5 | Direct CALL parents | **Falsified** — only DATA xref `0x00aa3d54` |
| 6 | Resize vec is `this` itself | **Falsified** — `ADD EBX,0x1C` before `FUN_0045c4b0` |
| 7 | Always succeeds | **Falsified** — returns 0 / -2 / -1 |
| 8 | Scaffold long Named_* is final product name | **Rejected** — use `_Inferred` structural |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| thiscall + RET 4 + return codes | **High** | Wrong port linkage |
| PBAM/TRAK gate + log path | **High** | Wrong chunk accept |
| this+0x1C Pod28 resize | **High** | Wrong container field |
| EFCT/SKEL type select | **High** | Wrong type tag |
| Full object map / nested formals | **Open** | Partial port |
| Runtime | **Open** | Matrix policy |

---

## 3. Cross-check against raw + bytes + sealed child

```
// StdVector_Resize_Pod28 (W35-M) sole parent = this unit @ 0x004599bf:
//   EBX = this+0x1C (vec)
//   ECX = count (ESI)
//   stack 0x1C-byte value
//   CALL 0045c4b0; RET 1C cleans value
```

Tag immediates in body hex match decompile constants. Path string matches scaffold evidence.

---

## 4. Surviving contract for AutoCore

```
// Animation track-master chunk load (server may not need retail dual I/O):
//   accept PBAM | TRAK
//   fill type EFCT|SKEL, name hashes, ints
//   resize List<Pod28> / vector at object+0x1C with default value
//   optional per-element load (FUN_0045dd60 residual)
// Do not invent stdcall without RET 4; do not treat as bare STL resize.
```

---

## 5. Verdict

Adversarial pass confirms A on sealed ABI/tags/resize/returns. Gaps are nested duals + product English + runtime → **accept-with-gaps**.
