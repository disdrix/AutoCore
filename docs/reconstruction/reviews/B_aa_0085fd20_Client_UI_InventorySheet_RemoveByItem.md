# Review B (skeptical / adversarial): `aa_0085fd20` Client_UI_InventorySheet_RemoveByItem

| Field | Value |
|---|---|
| **Stable ID** | `aa_0085fd20` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_0085fd20_Client_UI_InventorySheet_RemoveByItem.md` |
| **Verdict** | **accept** |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | Sets ESI sheet itself | Body never touches ESI | **Falsified** — caller must set |
| 2 | Removes from server inventory | Only UI sheet remove callee | **Falsified** as server path |
| 3 | Different COID order than parent | Pushes hi then lo; matches `0085fcc0` stack layout (lo @ stack0 after pushes) | **Survives** with parent dual |
| 4 | Has branches / null checks | Five instructions, no tests | **Falsified** |
| 5 | Is the hash remove itself | Hash remove is `00413a60` inside `0085fcc0` | **Falsified** |

---

## 2. Live ≡ raw

```
0085fd20  mov ecx, [eax+0x164]
0085fd26  mov edx, [eax+0x160]
0085fd2c  push ecx
0085fd2d  push edx
0085fd2e  call FUN_0085fcc0
0085fd33  ret
```

Matches raw decompile and parent dual §7.1 exactly.

---

## 3. Surviving contract

```
// EAX=item*, ESI=sheet*
// RemoveByCoid(item->coidLo(+0x160), item->coidHi(+0x164))
```

**Verdict:** **accept**.
