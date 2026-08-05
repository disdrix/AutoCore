# Review B (skeptical / adversarial): `aa_0051e4d0` CNDHash_Insert_009ce0a8

| Field | Value |
|---|---|
| **Stable ID** | `aa_0051e4d0` |
| **VA** | `0x0051e4d0` |
| **Canonical name** | `CNDHash_Insert_009ce0a8` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_0051e4d0_CNDHash_Insert_009ce0a8.md` |
| **System** | missions-progression (medal hash insert) |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | Builds / materializes MedalDef | Body only allocs hash **node** and links | **Falsified** — pure insert |
| 2 | Soft flag = multi-value same key | Soft hit returns **1**, no second node | **Falsified** multi-insert |
| 3 | Soft flag 0 = replace | Flag 0 → hard dup **E_FAIL** | **Falsified** replace |
| 4 | Lock aborts insert | Logs then continues | **Falsified** hard abort |
| 5 | Same as `FUN_0051e6d0` / `0053c560` | CF matches; vtbl **`009ce0a8` ≠ `009cb968`/`009cefd4`** | **Falsified** identity — twin |
| 6 | `FUN_0053ada0` is `operator_new` | Freelist slabs; ECX=`this+0x20` | **Falsified** plain new |
| 7 | Returns MedalDef* | Returns HRESULT-style int | **Falsified** pointer return |
| 8 | Many call sites | Sole static xref from `FUN_00519660` | **Agree** |
| 9 | Parent uses soft flag 1 | Parent pushes **0** after own allocation | **Agree** soft arm unused at known site |

---

## 2. Live ≡ raw

```
ret 0x0C on all exits
B8 03 40 00 80 / B8 05 40 00 80 / B8 01 00 00 00
8D 4F 20 ; CALL FUN_0053ada0
C7 06 A8 E0 9C 00          ; node vtbl 0x009ce0a8
bucket: key & mask → sentinel+4 head-insert
list append + count++

Parent 0051976a..74:
  MOV EAX,[EDI] ; id
  PUSH 0 / PUSH EDI / PUSH EAX
  MOV ECX, 0xb042e0
  CALL 0051e4d0
```

---

## 3. Soft-flag policy (same family)

| softIfExists | key present | Result |
|---|---|---|
| 0 | yes | `0x80004005` + log |
| ≠0 | yes | return **1**, map unchanged |
| * | no | insert, return 0 |

**Verdict:** **accept-with-gaps.**
