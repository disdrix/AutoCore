# Review B (skeptical / adversarial): `aa_00573a30` FriendsList_FindEntryByNameI_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00573a30` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-08-05` |
| **Counterpart** | `reviews/A_aa_00573a30_FriendsList_FindEntryByNameI_Inferred.md` |
| **Agent** | R11-005 OWN-ONLY dual |
| **Verdict** | **accept-with-gaps** on CF/role; product host class remains open |

---

## 1. Claims under attack

| # | Claim | Attack result |
|---|---|---|
| 1 | Skill-cast / ability residual math (partition nest skills-abilities) | **Falsified as cast** — pure social list walk; consumers are friends UI / `/friend` / button id `0x1117a` |
| 2 | Case-sensitive `strcmp` | **Falsified** — body uses **`_stricmp`** via IAT |
| 3 | Binary search / sorted map | **Falsified** — linear index 0..count-1 |
| 4 | Name at `entry+0` or `entry+0x10` (sibling merge) | **Falsified** — compare **`entry+0x1a`**; sibling `00573af0` is +0x10 on different vector |
| 5 | Count stored as fixed int field | **Falsified** — count from pointer span `>>2` |
| 6 | Returns index / bool | **Falsified** — returns **entry pointer** or 0 |
| 7 | Fastcall / pure cdecl | **Falsified** — `MOV ESI,ECX`; stack name; **`RET 0x4`** thiscall |
| 8 | Same function as `NameTable_FindEntryByNameI` (`00573af0`) | **Falsified** — different vector offsets (+0x8 vs +0x38) and name keys (+0x1a vs +0x10) |
| 9 | Always friends product name without `_Inferred` | **Unproven for class** — role High from English callers; PDB class open |
| 10 | Runtime Confirmed / Terminal | **Rejected** — no Launcher; Terminal false |
| 11 | Mutates list / removes entry | **Falsified** — read-only scan |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| `_stricmp` + name@+0x1a | **Confirmed** | wrong key → always miss |
| Vector @ +0x8/+0xc | **Confirmed** | wrong container |
| Null on miss/empty | **Confirmed** | NRE on ports |
| Friends-list call role | **High** | wrong system tagging |
| Product host type English | **Open** | naming only |
| Entry full layout | **Partial** | partial port of entry struct |

---

## 3. Cross-check

```
FUN_0082f9a0 UI_InteractionMenu_AddFriendsToggle [dualed]:
  ECX = DAT_00d1da2c; push target name → this unit
  non-zero → Remove Friends (0x1117a); zero path → Add (0x11177)

FUN_0094d900 /friend residual:
  hit → "That person is already on your friends list."
  miss → packet 0x801f add-friend

FUN_00830010 case 0x1117a Remove Friends:
  FUN_00573a30 → FUN_0094c680(*(entry+8), *(entry+0xc))

Sibling FUN_00573af0 [dualed NameTable_FindEntryByNameI]:
  this+0x38/+0x3c, entry+0x10 — Ignore/channel family; do not merge

Sibling FUN_00573a90:
  this+0x38 TFID pair match — not name
```

**Attack on “skills system core”:** partition nest is residual score parent only; live edges are social UI / chat friend command.

**Attack on “host is target character”:** dualed parent B already falsified — this = `DAT_00d1da2c` list host, not menu/target.

---

## 4. Surviving contract for AutoCore

```csharp
object? FriendsList_FindEntryByNameI(FriendsListHost self, string name)
{
    var begin = self.Begin; // +0x08
    var end = self.End;     // +0x0c
    if (begin == IntPtr.Zero) return null;
    int n = (int)((end - begin) / 4);
    for (int i = 0; i < n; i++) {
        var entry = begin[i];
        if (string.Equals(entry.NameAt0x1a, name, StringComparison.OrdinalIgnoreCase))
            return entry;
    }
    return null;
}
```

**Port traps:**

- `StringComparison.Ordinal` (case-sensitive) instead of ignore-case.
- Treating return as index / bool.
- Merging with `00573af0` (+0x38 / +0x10).
- Assuming sorted for binary search.
- Using menu/target as `this` instead of friends-list host.

---

## 5. Residual risks

- Product type of `DAT_00d1da2c` multi-list host (friends @+0x8 and other tables @+0x38) not fully typed.
- Entry packing before +0x1a (26-byte prefix) unknown.
- Not skill-cast residual math — parent matrix should tag **UI / social**.

**Verdict:** **accept-with-gaps** — no CF reject; adversarial attacks on cast-role / strcmp / sibling-merge / index-return falsified.
