# Review B (skeptical / adversarial): `aa_00765740` GfxBody_UnserializeGBOD_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00765740` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-08-04` (OWN-ONLY W37-S) |
| **Counterpart** | `reviews/A_aa_00765740_GfxBody_UnserializeGBOD_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | cdecl / thiscall ECX-body | **Falsified** — epilogue `RET 8` (`c2 08 00`); two stack formals |
| 2 | Tag is ASCII string `"GBOD"` compare | **Falsified** — DWORD `0x47424F44`; file order `DOBG` |
| 3 | Only version 1 supported | **Falsified** — arms for 1, 2, 3; else log invalid version |
| 4 | Failure aborts entire function immediately on any helper fail | **Partial falsify** — OR-accumulates; only v2/v3 factory path early-exits on status `<0` |
| 5 | MapB always runs | **Falsified** — only non-v1 path after bool read + `FUN_00437c90` |
| 6 | Name is Confirmed product symbol | **Careful** — plates prove gfxBody unserialize; method English remains **Inferred** |
| 7 | `reader[0x1011]` is element count | **Falsified** — mode gate selecting helper family (`+0x4044`) |
| 8 | Function is pure geometry piece serialize | **Falsified** — unserialize direction; EnterChunkScope + factory create |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| stdcall 2-arg + status return | **High** | ABI crash |
| GBOD tag + version dispatch | **High** | Wrong asset load |
| Status OR policy | **High** | Silent partial fail |
| MapA factory sites | **High** | Missing child objects |
| Copy 12 dwords `+4→+0x34` | **High** | Transform/state skew |
| Field English | **Low** | Port mis-layout |
| Nested helpers | **Open** | Incomplete port |
| Runtime | **Open** | Matrix policy |

---

## 3. Cross-check against raw + bytes + xrefs

```
// Body: 0x00765740–0x00766045 (2310 B); SEH LAB_009b31c4
// Tag cmp: 81 7c 24 3c 44 4f 42 47
// Epilogue: ADD ESP,0x5C; RET 8
// Plates @ 00a9dc40 / 00a9dc0c + gfxBody.cpp path
// Caller: FUN_0073eb40 @ 0073ebce (SAMB peek branch then this)
// Nested: FUN_00437b00 (W36-A), FUN_00437c90 (W36-C)
// Live decompile 2026-08-04 ≡ raw 2026-07-23 CF (+ W37-S seal)
```

---

## 4. Surviving contract for AutoCore

```
// Port as GBOD root unserialize (not GPCE piece, not serialize):
uint32_t GfxBody_UnserializeGBOD(void* body, StoChunkReader* reader);
// stdcall 2 args. Require tag GBOD; versions 1|2|3 only.
// OR status; v2/v3 factory may early-out on negative status.
// Copy 12 dwords body+4 → body+0x34 before leave.
// Do NOT invent product method English; keep Inferred.
// Pair MapA/MapB with W36 duals. Terminal coverage false.
```

---

## 5. Verdict

Adversarial pass confirms A on ABI, tag/version gates, status policy, and plates. Residual field English / nested helpers / runtime → **accept-with-gaps**.
