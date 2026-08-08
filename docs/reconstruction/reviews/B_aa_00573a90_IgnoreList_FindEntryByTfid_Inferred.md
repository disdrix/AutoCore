# Review B (skeptical / adversarial): `aa_00573a90` IgnoreList_FindEntryByTfid_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00573a90` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-08-05` |
| **Counterpart** | `reviews/A_aa_00573a90_IgnoreList_FindEntryByTfid_Inferred.md` |
| **Agent** | R12-025 OWN-ONLY dual (dual start 2646) |
| **Verdict** | **accept-with-gaps** on CF/role; product host class remains open |

---

## 1. Claims under attack

| # | Claim | Attack result |
|---|---|---|
| 1 | Skill-cast / ability residual math (partition nest skills-abilities) | **Falsified as cast** — pure social list walk; consumers are ignore remove, trade refuse, convoy decline, broadcast bubble gate |
| 2 | Case-insensitive name compare (`_stricmp`) | **Falsified** — body is dual int CMP on +8/+0xc; no string callee |
| 3 | Binary search / sorted map | **Falsified** — linear index 0..count-1 |
| 4 | Friends-list vector (+0x8) / name@+0x1a | **Falsified** — vector **+0x38/+0x3c**; keys are TFID ints |
| 5 | Same function as `NameTable_FindEntryByNameI` (`00573af0`) | **Falsified** — same vector, different key (TFID vs name@+0x10) and RET width (0x8 vs 0x4) |
| 6 | Same as friends TFID twin `FUN_005739d0` | **Falsified** — that twin walks **+0x8** friends vector |
| 7 | Count stored as fixed int field | **Falsified** — count from pointer span `>>2` |
| 8 | Returns index / bool | **Falsified** — returns **entry pointer** or 0 |
| 9 | Fastcall / pure cdecl / RET 0x4 | **Falsified** — thiscall; stack two dwords; **`RET 0x8`** |
| 10 | Always product name without `_Inferred` | **Unproven for class** — role High from English callers; PDB class open |
| 11 | Runtime Confirmed / Terminal | **Rejected** — no Launcher; Terminal false |
| 12 | Mutates list / removes entry | **Falsified** — read-only scan (mutate is caller `FUN_00573ce0` / `FUN_005746e0`) |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| TFID @ +8/+0xc | **Confirmed** | wrong key → always miss |
| Vector @ +0x38/+0x3c | **Confirmed** | wrong container (friends vs ignore) |
| Null on miss/empty | **Confirmed** | NRE on ports |
| Ignore-list call role | **High** | wrong system tagging |
| Product host type English | **Open** | naming only |
| Entry full layout | **Partial** | partial port of entry struct |

---

## 3. Cross-check

```
FUN_0080eeb0 remove-from-ignore residual:
  FUN_00573a90(tfid) → hit + entry+0x10 name
  → sprintf("%s has been removed from your ignore list.")
  → FUN_00573ce0(...); CDlgTabsSocial refresh

FUN_0080a170 trade residual:
  hit → local_108=1 auto-refuse sector packet
  (also "Trade refused." path elsewhere)

FUN_0080fa50 convoy invite:
  miss → "has invited you to join a convoy" / join prompt
  hit → auto packet 0x8006 decline

Client_RecvBroadcast [dualed]:
  float-text bubble only if FUN_00573a90(object_tfid) == 0

Sibling FUN_00573af0 [dualed NameTable_FindEntryByNameI]:
  this+0x38/+0x3c, entry+0x10 name — UI_InteractionMenu_AddIgnoreToggle
  same ignore table; do not merge keys

Sibling FUN_00573a30 [dualed FriendsList_FindEntryByNameI]:
  this+0x8/+0xc, entry+0x1a — friends; do not merge

Sibling FUN_005739d0:
  this+0x8 TFID twin for friends — do not merge
```

**Attack on “skills system core”:** partition nest is residual score parent only; live edges are social ignore / chat / trade / convoy.

**Attack on “this is friends TFID find”:** friends TFID twin is `FUN_005739d0` at **+0x8**; this unit is **+0x38** (ignore table per English).

---

## 4. Surviving contract for AutoCore

```csharp
object? IgnoreList_FindEntryByTfid(IgnoreListHost self, int tfidLo, int tfidHi)
{
    var begin = self.Begin; // +0x38
    var end = self.End;     // +0x3c
    if (begin == IntPtr.Zero) return null;
    int n = (int)((end - begin) / 4);
    for (int i = 0; i < n; i++) {
        var entry = begin[i];
        if (entry.TfidLo == tfidLo && entry.TfidHi == tfidHi)
            return entry;
    }
    return null;
}
```

**Port traps:**

- Using friends vector offsets (+0x8/+0xc) instead of ignore (+0x38/+0x3c).
- Treating return as index / bool.
- Merging with `00573af0` (name key) or `005739d0` (friends TFID).
- Assuming sorted for binary search.
- Using `RET 0x4` (one stack arg) instead of **`RET 0x8`**.
- Using menu/target as `this` instead of multi-list host (`DAT_00d1da2c`).

---

## 5. Residual risks

- Product type of `DAT_00d1da2c` multi-list host (friends @+0x8 and ignore @+0x38) not fully typed.
- Entry packing beyond TFID and name@+0x10 unknown.
- Not skill-cast residual math — parent matrix should tag **UI / social**.

**Verdict:** **accept-with-gaps** — no CF reject; adversarial attacks on cast-role / name-merge / friends-merge / index-return falsified.
