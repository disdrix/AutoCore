# Annotated: Deliver CargoReady (`aa_00610f20`)

Pure readiness predicate: `req+0x18 == matchKey` AND cargo grid present AND (`count(CBID) ≥ need` **OR** `+0x23 == 0`). Returns AL 1/0. Uses `CountItemsByCbid` with `includeBroken=0`. No side effects.

| Offset | Role |
|-------:|------|
| +0x10 | CBID (`CBIDItem`) |
| +0x14 | need (`NumToDeliver`) |
| +0x18 | match key (NPC/target / event id) |
| +0x23 | **require-count / enforce-qty** — default **1**; **`== 0` bypasses quantity** (not skip-when-set) |

### `+0x23` polarity (sealed 2026-07-29)

| Value | Effect in this body |
|------:|---------------------|
| **0** | Qty waived — ready if match + non-null cargo grid |
| **≠0** | Must have `count >= need` |

**Source:** ctor `0x00610bc0` writes **1**. XML `CBIDItem` parse writes **0** when parsed int is **−1**; otherwise leaves **1**. Not a separate GetFlags tag.

### ABI

`__thiscall(req, matchKey, character)` · **`RET 8`** · virtual at Deliver vtbl **`+0x38`**.

### Raw note

Host pointer at `character+0x250` is **not** null-checked in image; only `host+0x2b0` (grid) is.

Confidence: CF **High**; `+0x23` polarity **High**; method name **Probable**/`_Inferred`.
