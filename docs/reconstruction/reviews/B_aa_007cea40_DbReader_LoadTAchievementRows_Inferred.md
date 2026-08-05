# Review B (skeptical / adversarial): `aa_007cea40` DbReader_LoadTAchievementRows_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_007cea40` |
| **VA** | `0x007cea40` |
| **Canonical name** | `DbReader_LoadTAchievementRows_Inferred` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_007cea40_DbReader_LoadTAchievementRows_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | Builds MedalDef / inserts hash | Only fills row vector + count; parent does new/fill/insert | **Falsified** def-build |
| 2 | Always uses COM/XML | Primary parent path runs when `DAT_00d1793c==0` (non-COM arm) | **Falsified** always-COM |
| 3 | `//tAchievement/row` unused on primary path | String only in `DAT_00d1793c!=0` arm; primary uses `this+0x28` path helper | **Survives as table identity** via same loader family + COM string; primary table name **Probable** not Confirmed from this body alone |
| 4 | Returns void | HRESULT; parent `CMP ESI,EBX` / `JGE` | **Falsified** void |
| 5 | outCount is byte size | Parent divides span by 0x3d4 for loop bound; stores count | **Falsified** byte-size-as-count |
| 6 | Multiple independent callers in medal path | Sole xref from `FUN_00519660` | **Agree** static |
| 7 | Clean scaffold is bit-exact | Large SEH/COM residual; many unreachable warnings | **Agree** structural only |
| 8 | Invalid names fully known | Only offsets used by fill dual sealed | **Agree** residual |

---

## 2. Live ≡ raw (structural)

```
if (*this == 0) return 0x80004004;
if (DAT_00d1793c == 0) {
  // query/bind/iterate → vector of 0x3d4 rows; *outCount = n
} else {
  // COM: SysAllocString(L"//tAchievement/row"); node walk; free
}
return 0; // success
```

Parent sandwich: enter `007e1d80` → this load → leave `007b7df0` on `*[00b0469c]`.

---

## 3. Surviving contract

```
// HRESULT LoadTAchievementRows(DbReaderCtx* this, int* outCount, Vector* rows0x3d4)
// Loads achievement/medal definition rows for FUN_00519660 → MedalDef table.
// Deep bind/COM fidelity residual; do not treat clean .cpp as bit-exact.
```

**Verdict:** **accept-with-gaps.**
