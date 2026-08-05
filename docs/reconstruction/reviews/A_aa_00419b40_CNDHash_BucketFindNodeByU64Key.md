# Review A (reconstruction fidelity): `aa_00419b40` CNDHash_BucketFindNodeByU64Key

| Field | Value |
|---|---|
| **Stable ID** | `aa_00419b40` |
| **VA** | `0x00419b40` |
| **Body** | `0x00419b40`–`0x00419b72` (**51** bytes; `ret 8`) |
| **Canonical name** | `CNDHash_BucketFindNodeByU64Key` (inferred) |
| **Ghidra name** | `FUN_00419b40` |
| **Prior alias** | `Named_CalleeOf_Named_VOG_DEBUG_STOP_00419b40` (xref-weak; superseded) |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review (OWN-ONLY dual A/B, W16-N) |
| **Counterpart** | `reviews/B_aa_00419b40_CNDHash_BucketFindNodeByU64Key.md` |
| **System** | container / CNDHash (u64-key; inventory-sheet family) |
| **Live tools** | Ghidra `decompile_function`, `read_memory`, `get_function_by_address`, `get_function_callers` (no `disassemble_bytes`) |
| **Verdict** | **accept** |

---

## 1. Purpose

**Singly-linked bucket-chain find** for the **u64-key** CNDHash node (0x28):

1. `node = *(EAX + 4)` — chain head from bucket header.
2. `*EDI = 0` — clear predecessor out-param.
3. Walk while node non-null and `(keyLo, keyHi) != (node+0x18, node+0x1c)`.
4. On non-match: `*EDI = node`; `node = *(node + 0x10)`.
5. Return matched **node*** in EAX, or **NULL**. Does **not** read value@`+0xc`.

Callers: insert soft/dup checks (`0x00413920`), payload lookup (`0x00413b30` returns `node+0xc`), unlink (`0x00419b80`), UI/map helpers.

Distinct from mission/generic `CNDHash_LookupByKey` (`0x005b0920`): that unit is **u32 key@+0x10**, **thiscall**, returns **value@+0x08**, no predOut.

---

## 2. Inspected artifacts

| Artifact | Path / source | This pass |
|---|---|---|
| Raw | `docs/reconstruction/raw/aa_00419b40_FUN_00419b40.md` | live append ≡ decompile |
| Annotated | `docs/reconstruction/raw/aa_00419b40_FUN_00419b40.annotated.md` | machine CF sealed |
| Clean | `docs/reconstruction/reconstructed-exact/FUN_00419b40.cpp` | CF ≡ raw |
| Named clean | `docs/reconstruction/reconstructed-exact/CNDHash_BucketFindNodeByU64Key.cpp` | same CF |
| Function record | `docs/reconstruction/functions/aa_00419b40_FUN_00419b40.md` | dual sealed |
| Live decompile | Ghidra `0x00419b40` | ≡ raw scaffold |
| Live body | `read_memory` length 51 | hex sealed below |
| Sibling insert | `A_aa_00413920_CNDHash_Insert_u64` | key/next offsets |
| Sibling lookup payload | `A_aa_00413b30_CoidMap_LookupPayload_Inferred` | returns value@+0xc |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Body `00419b40`–`00419b72`, `ret 8` | **Confirmed** | last 3 bytes `c2 08 00` |
| EAX = bucket header; load head @+4 | **Confirmed** | `8b 40 04` |
| EDI = predOut; `*EDI=0` then predecessors | **Confirmed** | `c7 07 00…` / `89 07` |
| Stack keyLo / keyHi stdcall | **Confirmed** | loads after push ebx/esi; `ret 8` |
| Compare keyLo@+0x18, keyHi@+0x1c | **Confirmed** | `8b 48 18` / `8b 50 1c` |
| Advance next@+0x10 | **Confirmed** | `8b 40 10` |
| Return node* (not value) | **Confirmed** | EAX left as node; `00413b30` loads +0xc after |
| Leaf / no callees | **Confirmed** | no CALL in body |
| Clean ≡ raw ≡ live CF | **Confirmed** | for-walk matches byte path |
| Product English name | **Probable** | inferred from CNDHash family |
| Runtime / bit-exact | **Open** | deferred |

---

## 4. Control flow: clean ≡ raw ≡ live

| Stage | Match |
|---|---|
| Load head from header+4 | **Yes** |
| Zero *predOut | **Yes** |
| Empty head → ret 0 | **Yes** (`jz` past loop) |
| Dual-dword key compare | **Yes** (both must match) |
| Non-match: store pred, follow +0x10 | **Yes** |
| Match: leave EAX=node, skip pred store | **Yes** |
| Miss: EAX=0, *predOut=last | **Yes** |
| `ret 8` | **Yes** |

### Recovered CF

```c
// EAX=header, EDI=predOut; stdcall keyLo,keyHi; ret 8
Node *CNDHash_BucketFindNodeByU64Key(uint32_t keyLo, uint32_t keyHi)
{
    Node *node = *(Node **)((char *)header + 4);
    *predOut = 0;
    if (!node) return 0;
    for (; node && (keyLo != node->keyLo || keyHi != node->keyHi);
         node = node->next) {
        *predOut = node;
    }
    return node; // match or NULL
}
```

### Body hex (51 bytes)

```
8b400485c0c707000000007423538b5c240c568b74240c8b48183bf18b501c75043bda740989078b401085c075e95e5bc20800
```

---

## 5. Layout (fields this unit touches)

**Bucket header:** `+0x04` head.

**Node (u64 family 0x28):** `+0x10` next, `+0x18` keyLo, `+0x1c` keyHi.

---

## 6. Callers / callees

**Callees:** none.

**Callers (Ghidra):** `00413920`, `00413b30`, `00419620`, `00419b80`, `007fe5b0`, `00800af0`, `00800c30`.

---

## 7. Gaps / open

1. English product name not PDB-proven — keep `_Inferred` / probable.
2. Full list of all call-site register setups (EAX/EDI) not audited per site beyond insert/remove duals.
3. Runtime multi-key collision walk not harnessed.

**Verdict:** **accept** — ABI, CF, offsets, and return width sealed from decompile + body bytes.
