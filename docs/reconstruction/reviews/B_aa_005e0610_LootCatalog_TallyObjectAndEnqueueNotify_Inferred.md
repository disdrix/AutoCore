# Review B (skeptical / adversarial): `aa_005e0610` LootCatalog_TallyObjectAndEnqueueNotify_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_005e0610` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-08-04` (OWN-ONLY W37-AA) |
| **Counterpart** | `reviews/A_aa_005e0610_LootCatalog_TallyObjectAndEnqueueNotify_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | Decompiler first counter uses `(uVar6>>32)` | **Falsified** — SIB is `[ESI+EDX*4+0x13ce0c]` with **EDX=M** from vfunc map; EBX=1 increment |
| 2 | Path0 and path1 notify use same `this` | **Falsified** — path1 `+0xC`, path0 `+0x8700C` after shared `u` |
| 3 | Function is mission-fail product logic | **Narrow/reject** — callee is dword vector push; mission plate is caller context only |
| 4 | Scaffold Mission_after_CVOGRegionMissions name | **Reject** — use loot-catalog `_Inferred` from sealed type→row + tally |
| 5 | `FUN_005e0480` returns 64-bit | **Falsified** — pure int row / −1 in EAX |
| 6 | Always notifies | **Falsified** — only `notifyPath` 0 or 1; other values tally-only |
| 7 | Type always `obj+0x38` | **Falsified** — 0xA/0xB kind shorts force 0x44/0x46 |
| 8 | Map insert this = stack pair | **Falsified** — `MOV ECX,ESI` (manager) before `005e18d0` |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| ABI RET 0x0C | **High** | Stack corruption |
| Type remap + row gate | **High** | Wrong catalog axis |
| Vfunc bucket M | **High** | Wrong counter column |
| Counter bases | **High** | Wrong stats |
| Notify grid formula | **High** | Wrong reaction list |
| Product bank English | **Low** | Labeling only |
| Val12 payload fields | **Med** | Map value shape |
| Runtime | **Open** | Matrix policy |

---

## 3. Cross-check against raw + bytes + xrefs

```
// CloneBase load FUN_00541e70 sites:
//   flag0: single band from cb+0x3f0
//   flag1 loop 0..0x4F when kind short == 8
//   flag1 single band otherwise when cb+0x3a8 == 1
// paired with FUN_005e0580 at each site (not OWN)
```

Live decompile matches scaffold raw skeleton but **must not** be ported for counter index 0 or notify this. Full-body hex seals M map, four `ADD` forms, and dual lea bases.

---

## 4. Surviving contract for AutoCore

```
// Port as CloneBase-load loot tally:
// thiscall manager; (obj, bandIndex, notifyPath); ret 0xC.
// type overrides from cb+0x3f4; row via LootCatalog_TypeCodeToRowIndex;
// skip (vfunc==-1 && type==0xE) and row<0;
// M = clamp-map vfunc to 0..3; P = max(0, band-1); S = race short;
// ++ four int counters; if path 0/1 push object id to grid vector.
// Do not trust decompiler for first counter index or notify this equality.
```

---

## 5. Verdict

Adversarial pass confirms A after applying byte corrections the decompiler missed. Residual product English + Val12 field detail + runtime → **accept-with-gaps**.
