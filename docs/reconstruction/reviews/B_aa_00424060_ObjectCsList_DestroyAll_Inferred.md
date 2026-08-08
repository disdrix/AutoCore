# Review B (skeptical / adversarial): `aa_00424060` ObjectCsList_DestroyAll_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00424060` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-08-05` (OWN-ONLY WQ9L-E) |
| **Counterpart** | `reviews/A_aa_00424060_ObjectCsList_DestroyAll_Inferred.md` |
| **Verdict** | **accept** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | Same body as `0051b8a0` (merge twins) | **Falsified** — that twin writes `node+4=0`; this unit does not (matches `0051bc90`) |
| 2 | This is list complete dtor | **Falsified** — callers still install vtbls + `DeleteCriticalSection` / free after |
| 3 | Frees list object | **Falsified** — no `operator_delete` here |
| 4 | stdcall / free function | **Falsified** — `MOV ESI,ECX` |
| 5 | Next pointer at `node+0x10` | **Falsified** — machine uses `node[2]` / `+8` |
| 6 | Throw is SEH-only AV | **Falsified** — explicit `_CxxThrowException` with `0x80070005` |
| 7 | TextMarkup-only / CNDUIWindow-only | **Falsified** — 22+ distinct callers across list families |
| 8 | Product name is invent | **Falsified** — SEH string contains **DestroyAll** |
| 9 | Scaffold "CalleeOf VOG_DEBUG_STOP" is primary | **Overstated** — VOG only in SEH catch log path; method is DestroyAll drain |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Drain under CS | **High** | UAF / lock bugs |
| No `node+4` clear | **High** | Wrong merge with 0051b8a0 |
| Flag throw 0x80070005 | **High** | Silent wrong path |
| DestroyAll product English | **High** | Naming only if string mis-bound |
| Family demangle ObjectCsList | **Medium** | Prefer CNDDoubleList for UI nest only |
| Runtime | **Open** | Matrix policy |

---

## 3. Cross-check against raw + bytes

Live 2026-08-05 ≡ raw 2026-07-23 CF. Twin decompile `0051bc90` identical CF. CNDUIWindow complete dual-calls with vtbl phase matching complete-dtor pattern of ObjectCsList family.

---

## 4. Surviving contract for AutoCore

```
// List method — DestroyAll drain (no node+4 clear):
ObjectCsList_DestroyAll_Inferred(list);
// Callers: complete/scalar list dtors; CNDUIWindow nested @+0x1E8 ×2.
// Twin: ObjectCsList_ClearDestroyNoNode4_Inferred (0x0051bc90) — same CF.
// Do NOT merge with ClearDestroy (0x0051b8a0) which zeros node+4.
```

---

## 5. Verdict

All structural adversarial claims falsified; product DestroyAll string seals method English. Family demangle residual acceptable under `_Inferred` → **accept**. Terminal **false**.
