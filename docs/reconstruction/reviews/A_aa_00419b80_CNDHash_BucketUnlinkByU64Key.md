# Review A (reconstruction fidelity): `aa_00419b80` CNDHash_BucketUnlinkByU64Key

| Field | Value |
|---|---|
| **Stable ID** | `aa_00419b80` |
| **VA** | `0x00419b80` |
| **Body** | `0x00419b80`–`0x00419bc9` (**73** bytes; `ret 8`) |
| **Canonical name** | `CNDHash_BucketUnlinkByU64Key` (inferred) |
| **Ghidra name** | `FUN_00419b80` |
| **Prior alias** | `Named_CalleeOf_Named_VOG_DEBUG_STOP_00419b80` (xref-weak; superseded) |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review (OWN-ONLY dual A/B, W18-P) |
| **Counterpart** | `reviews/B_aa_00419b80_CNDHash_BucketUnlinkByU64Key.md` |
| **System** | container / CNDHash (u64-key; inventory-sheet family) |
| **Live tools** | Ghidra `decompile_function`, `read_memory`, `analyze_function_complete`, `get_function_by_address` (no `disassemble_bytes`) |
| **Verdict** | **accept** |

---

## 1. Purpose

**Bucket-chain find + unlink** for the u64-key CNDHash node (0x28 family):

1. `node = CNDHash_BucketFindNodeByU64Key(bucket, &pred, keyLo, keyHi)` with **EBX→EAX** header and predOut in the **keyLo stack slot**.
2. If node non-null:
   - If pred non-null → `pred->next (+0x10) = node->next`.
   - Else → `bucket->head (+4) = node->next`.
3. Always `FUN_00419ad0` with **EDI = bucket** (touch-bit walk / cycle repair).
4. Return **node*** (or NULL). Does **not** free, dtor value, or unlink ordered list.

Primary parent: `CNDHash_Remove_u64` (`0x00413a60`) — after this returns, parent transfers value@`+0xc`, unlinks `+0x20/+0x24` list, freelist-pushes node.

Sibling find dual: `aa_00419b40` **accept**.

---

## 2. Inspected artifacts

| Artifact | Path / source | This pass |
|---|---|---|
| Raw | `docs/reconstruction/raw/aa_00419b80_FUN_00419b80.md` | v2026-07-29 append ≡ live |
| Annotated | `docs/reconstruction/raw/aa_00419b80_FUN_00419b80.annotated.md` | machine CF sealed |
| Clean | `docs/reconstruction/reconstructed-exact/CNDHash_BucketUnlinkByU64Key.cpp` | CF ≡ bytes |
| Scaffold clean | `docs/reconstruction/reconstructed-exact/FUN_00419b80.cpp` | decompiler-shaped |
| Function record | `functions/aa_00419b80_CNDHash_BucketUnlinkByU64Key.md` | dual sealed |
| Live decompile | Ghidra `0x00419b80` | ≡ raw scaffold |
| Live body | `read_memory` length 80 | hex sealed below |
| Sibling find | `A_aa_00419b40_CNDHash_BucketFindNodeByU64Key` | same offsets |
| Parent remove | `A_aa_00413a60_CNDHash_Remove_u64` | sole high-value consumer |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Body `00419b80`–`00419bc9`, `ret 8` | **Confirmed** | last 3 bytes `c2 08 00` |
| EBX = bucket header | **Confirmed** | `8b c3` into find; `[ebx+4]` head store |
| Stack keyLo/keyHi stdcall | **Confirmed** | loads + `ret 8` |
| predOut = keyLo slot reuse | **Confirmed** | `lea edi,[esp+14]` then post-call `[esp+0xc]` |
| Splice via next@`+0x10` | **Confirmed** | `8b 46 10` / `89 41 10` |
| Head vs mid branch | **Confirmed** | `test ecx` / `jz` head store |
| Always `FUN_00419ad0` | **Confirmed** | both hit paths + miss |
| Return node* not value | **Confirmed** | `mov eax,esi` |
| Clean ≡ raw ≡ live CF | **Confirmed** | after trap correction |
| Product English name | **Probable** | inferred from family |
| Runtime / bit-exact | **Open** | deferred |

---

## 4. Control flow: clean ≡ raw ≡ live

| Stage | Match |
|---|---|
| Find with EBX header + EDI predOut | **Yes** |
| Miss → ad0 → ret 0 | **Yes** |
| Hit + pred → pred->next = next | **Yes** |
| Hit + no pred → head = next | **Yes** |
| ad0 with EDI=bucket | **Yes** |
| ret 8 / EAX=node | **Yes** |

**Body hex:**  
`8b4424088b4c2404565750518d7c24148bc3e8a9ffffff8bf085f6741f8b4c240c85c98b461074118bfb894110e81effffff5f8bc65ec208008943048bfbe80dffffff5f8bc65ec20800`

---

## 5. Decompiler traps (fidelity)

1. **`param_1` at the pred test is not keyLo** — find overwrites the keyLo stack slot with predecessor.
2. **`unaff_EBX` is intentional ABI** (bucket), not noise.
3. Scaffold raw body kept for provenance; named clean documents machine truth.

---

## 6. Gaps

1. Product/PDB symbol.
2. Full audit of `FUN_004197b0` call site (same family; out of deep OWN except xref).
3. Runtime / bit-exact.

**Verdict:** **accept** — CF/ABI/offsets Confirmed; English name Probable only.
