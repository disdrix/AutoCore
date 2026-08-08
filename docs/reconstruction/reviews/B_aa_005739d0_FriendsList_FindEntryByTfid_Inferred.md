# Review B (skeptical / adversarial): `aa_005739d0` FriendsList_FindEntryByTfid_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_005739d0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-08-05` |
| **Counterpart** | `reviews/A_aa_005739d0_FriendsList_FindEntryByTfid_Inferred.md` |
| **Agent** | R13-039 OWN-ONLY dual (dual start 2686) |
| **Verdict** | **accept-with-gaps** on CF/role; product host class remains open |

---

## 1. Claims under attack

| # | Claim | Attack result |
|---|---|---|
| 1 | Skill-cast / ability residual math (partition nest skills-abilities) | **Falsified as cast** — pure social list walk; consumers are friend presence notify + insert helpers |
| 2 | Case-insensitive name compare (`_stricmp`) | **Falsified** — body is dual int CMP on +8/+0xc; no string callee (leaf) |
| 3 | Binary search / sorted map | **Falsified** — linear index 0..count-1 |
| 4 | Ignore-list vector (+0x38) | **Falsified** — vector **+0x8/+0xc** (friends table per dualed name sibling + English) |
| 5 | Same function as `FriendsList_FindEntryByNameI` (`00573a30`) | **Falsified** — same vector, different key (TFID vs name@+0x1a) and RET width (0x8 vs 0x4) |
| 6 | Same as ignore TFID twin `FUN_00573a90` | **Falsified** — that twin walks **+0x38** ignore vector |
| 7 | Count stored as fixed int field | **Falsified** — count from pointer span `>>2` |
| 8 | Returns index / bool | **Falsified** — returns **entry pointer** or 0 |
| 9 | Fastcall / pure cdecl / RET 0x4 | **Falsified** — thiscall; stack two dwords; **`RET 0x8`** |
| 10 | Always product name without `_Inferred` | **Unproven for class** — role High from English callers; PDB class open |
| 11 | Runtime Confirmed / Terminal | **Rejected** — no Launcher; Terminal false |
| 12 | Mutates list / removes entry | **Falsified** — read-only scan (mutate is caller `FUN_005746e0`) |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| TFID @ +8/+0xc | **Confirmed** | wrong key → always miss |
| Vector @ +0x8/+0xc | **Confirmed** | wrong container (friends vs ignore) |
| Null on miss/empty | **Confirmed** | NRE on ports |
| Friends-list call role | **High** | wrong system tagging |
| Product host type English | **Open** | naming only |
| Entry full layout | **Partial** | partial port of entry struct |

---

## 3. Cross-check

```
FUN_0080f3b0 presence residual:
  flag==0 → FUN_00573b50(tfid) → "Your enemy" + entry+0x23 name
  flag!=0 → FUN_005739d0(tfid) → "Your friend" + entry+0x1a name
  then "come online." / "gone offline." floater

FUN_00574020 / FUN_00574270 insert-if-missing residual:
  FUN_005739d0(entry_tfid) → 0 then FUN_005746e0(&param)

Sibling FUN_00573a30 [dualed FriendsList_FindEntryByNameI]:
  this+0x8/+0xc, entry+0x1a name — UI_InteractionMenu_AddFriendsToggle
  same friends table; do not merge keys

Sibling FUN_00573a90 [dualed IgnoreList_FindEntryByTfid]:
  this+0x38/+0x3c, TFID@+8/+0xc — ignore; do not merge vectors

Sibling FUN_00573af0 [dualed NameTable_FindEntryByNameI]:
  this+0x38, name@+0x10 — ignore name; do not merge
```

**Attack on “skills system core”:** partition nest is residual score parent only; live edges are social friends presence / list insert.

**Attack on “this is ignore TFID find”:** ignore TFID twin is `FUN_00573a90` at **+0x38**; this unit is **+0x8** (friends table per dualed name sibling + English).

---

## 4. Surviving contract for AutoCore

```csharp
object? FriendsList_FindEntryByTfid(FriendsListHost self, int tfidLo, int tfidHi)
{
    var begin = self.Begin; // +0x8
    var end = self.End;     // +0xc
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

- Using ignore vector offsets (+0x38/+0x3c) instead of friends (+0x8/+0xc).
- Treating return as index / bool.
- Merging with `00573a30` (name key) or `00573a90` (ignore TFID).
- Assuming sorted for binary search.
- Using `RET 0x4` (one stack arg) instead of **`RET 0x8`**.
- Using menu/target as `this` instead of multi-list host (`DAT_00d1da2c`).

---

## 5. Residual risks

- Product type of `DAT_00d1da2c` multi-list host (friends @+0x8 and ignore @+0x38) not fully typed.
- Entry packing beyond TFID and name@+0x1a unknown.
- Not skill-cast residual math — parent matrix should tag **UI / social**.

**Verdict:** **accept-with-gaps** — no CF reject; adversarial attacks on cast-role / name-merge / ignore-merge / index-return falsified.
