# Review B (skeptical / adversarial): `aa_0051bfb0` CNDHash_ReclaimAll_ValueOwning_009ce0a8

| Field | Value |
|---|---|
| **Stable ID** | `aa_0051bfb0` |
| **VA** | `0x0051bfb0` |
| **Canonical name** | `CNDHash_ReclaimAll_ValueOwning_009ce0a8` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_0051bfb0_CNDHash_ReclaimAll_ValueOwning_009ce0a8.md` |
| **System** | container / medal CNDHash |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | Full FreeBuckets / table free | Body never touches `+0x10` free or `count` | **Falsified** as FreeBuckets |
| 2 | Non-owning reclaim only | Value path always can delete `node+8` | **Falsified** pure non-owning |
| 3 | Plain `operator_delete` only like `009cefec` | Bytes insert `FUN_00604e30` thiscall first | **Falsified** merge with plain owning |
| 4 | `operator_delete` noreturn | `ADD ESP,4` + freelist push after | **Falsified** decompiler warning |
| 5 | Zeros freelist / count | Only pushes onto `+0x20`; count untouched | **Falsified** |
| 6 | Many static callers | Exactly **1** xref: FreeBuckets `0051d15a` | **Agree** |
| 7 | PDB name proven | No body string | **Agree Open** product; role High OK |
| 8 | Named_VOG chain identity | No string on this body | **Falsified** |

---

## 2. Live ≡ raw

```
Live decompile ≡ raw 2026-07-23.
read_memory 0x72 B through 5F 5E 5D 5B 59 C3.
Stamp imm 009ce0a8; freelist +0x20; JBE vs mask +8.
Caller: only FUN_0051d150 @ 0051d15a.
```

Nested residual cross-check (`FUN_00604e30` — not owned):

```
thiscall value: if value+4/+8/+0xC/+0x10 non-null → operator_delete each, zero.
Then parent operator_delete(value).
```

⇒ Distinguishes stamp `009ce0a8` value payload from plain owning siblings. **Agree High** with A.

---

## 3. Surviving contract

```
// void __thiscall CNDHash_ReclaimAll_ValueOwning_009ce0a8(hash*)
// for i in 0..mask inclusive:
//   walk chain at table[i]->head; nested-teardown+delete values;
//   push nodes to freelist; clear heads.
// Does not free table, zero count, or free freelist storage.
```

---

## 4. CF challenge of Review A

- Inclusive mask loop / freelist push / clear heads: **agree Confirmed**
- thiscall plain ret: **agree Confirmed**
- Nested teardown before delete: **agree Confirmed** (stronger than plain owning)
- Stamp-qualified name: **agree** — matches sibling vocabulary
- Do not merge with FreeBuckets or Alloc: **agree**
- Optional NestedOwning rename: **agree unnecessary** unless registry collision

---

## 5. Residual risks

1. Product type of value (medal payload fields beyond residual).
2. Whether null values are common (insert always alloc?) — delete guarded.
3. Double-delete if freelist node reused without value clear (contract: clear + push).
4. Product English Reclaim vs Clear vs RemoveAll.
5. Runtime / bit-exact / differential not run.

**Verdict:** **accept-with-gaps.** Agree with A on ABI, CF, callers, nested-owning role, and name.
