# Review B (skeptical / adversarial): `aa_00604e30` CNDHash_ValueClearOwnedPtrs

| Field | Value |
|---|---|
| **Stable ID** | `aa_00604e30` |
| **VA** | `0x00604e30` |
| **Canonical name** | `CNDHash_ValueClearOwnedPtrs` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_00604e30_CNDHash_ValueClearOwnedPtrs.md` |
| **System** | container / medal CNDHash |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | Full value dtor (frees self) | Body never `operator_delete(this)` / ESI | **Falsified** as scalar dtor |
| 2 | Only two slots | Bytes hit +4/+8/+0xC/+0x10 | **Falsified** undercount |
| 3 | `operator_delete` noreturn | `ADD ESP,4` + next zero always | **Falsified** decompiler warning |
| 4 | Leaves slots non-zero after delete | Always `MOV [ESI+off], EDI` | **Falsified** |
| 5 | Touches value vtbl/+0 | No store to `[ESI]` | **Falsified** |
| 6 | Many unrelated callers | Exactly **2** xrefs: reclaim + scalar dtor | **Agree** |
| 7 | PDB name proven | No body string | **Agree Open** product; role High OK |
| 8 | Named_VOG chain identity | No string on this body | **Falsified** |

---

## 2. Live ≡ raw

```
Live decompile ≡ raw 2026-07-23.
read_memory 0x55 B through 5F 5E C3.
Callers: FUN_0051bfb0 @ 0051bfe4; FUN_0051bd90 @ 0051bda3.
```

Parent reclaim (W25-F, sealed): `MOV ECX, value; CALL FUN_00604e30; PUSH value; operator_delete`.

⇒ Nested clear before free is the distinguishing trait of stamp `009ce0a8` values. **Agree High** with A.

---

## 3. Surviving contract

```
// void __thiscall CNDHash_ValueClearOwnedPtrs(value*)
// delete-if-nonnull + zero four owned ptr slots at +4/+8/+0xC/+0x10
// does not free value; does not rewrite +0
```

---

## 4. CF challenge of Review A

- Four-slot matrix: **agree Confirmed**
- thiscall plain ret: **agree Confirmed**
- operator_delete returns: **agree Confirmed**
- Role nested value clear: **agree High**
- Reject Named_VOG alias: **agree**
- Name not PDB: **agree Open** product English

---

## 5. Residual risks

1. Pointee product types of the four slots.
2. Whether any slot can hold non-`operator_delete` allocators (always uses `operator_delete` here).
3. Double-clear safety if called twice (null checks + zero — safe).
4. Runtime / bit-exact / differential not run.

**Verdict:** **accept-with-gaps.** Agree with A on ABI, CF, callers, and role.
