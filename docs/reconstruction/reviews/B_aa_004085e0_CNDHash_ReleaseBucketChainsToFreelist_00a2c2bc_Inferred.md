# Review B (skeptical / adversarial): `aa_004085e0` CNDHash_ReleaseBucketChainsToFreelist_00a2c2bc_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004085e0` |
| **VA** | `0x004085e0` |
| **Canonical name** | `CNDHash_ReleaseBucketChainsToFreelist_00a2c2bc_Inferred` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-08-04` |
| **Counterpart** | `reviews/A_aa_004085e0_CNDHash_ReleaseBucketChainsToFreelist_00a2c2bc_Inferred.md` |
| **System** | container / CNDHash |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | This is destroy-bucket-table (parent) | No free/delete[] of table; no live@+0x0c zero | **Falsified** merge with `00406fc0` |
| 2 | Thiscall ECX (skill freelist) | Entry uses **EBX** table load; parent `mov ebx,eax` | **Falsified** thiscall |
| 3 | Tree free-subtree / map erase | Hash bucket table + freelist head `@+0x20` | **Falsified** tree |
| 4 | Same as tree++ neighbor `00408590` | Different CF (isnil walk vs freelist) | **Falsified** VA-neighbor merge |
| 5 | Frees the node with `operator_delete` | Only payload `node[3]`; node recycled to freelist | **Falsified** node-free |
| 6 | Zeros mask / ordered lists | Only chain heads + freelist + payload | **Falsified** |
| 7 | VOG_DEBUG_STOP domain logic | No strings; pure container helper | **Falsified** domain |
| 8 | Product English sealed | Stamp `00a2c2bc` only | **Agree** `_Inferred` |
| 9 | Runtime Confirmed | No Launcher | **Agree** open |
| 10 | `operator_delete` aborts freelist push | Fall-through after delete is in raw/live CF | **Falsified** as runtime fact; decomp warning only |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| EBX ABI / bare ret | **Confirmed** | Stack/reg imbalance |
| Freelist push `@+0x20` | **Confirmed** | Node leak / double-free |
| Payload-only delete | **Confirmed** | Heap corruption if node deleted |
| Bucket loop inclusive mask | **Confirmed** | Miss last bucket |
| Sole listed caller | **Confirmed** | Miss if xrefs incomplete |
| Runtime | **Open** | No live freelist capture |

---

## 3. Cross-check against raw / live / bytes

```
raw scaffold CF ≡ live batch_decompile (2026-08-04);
bytes @ 0x004085e0:
  push ebp; push esi; xor ecx; push edi; xor ebp
  mov eax,[ebx+0x10]          ; table
  … walk chains …
  imm32 BC C2 A2 00           ; PTR_FUN_00a2c2bc
  call operator_delete        ; payload only
  … freelist link @ [ebx+0x20] …
  pop edi; pop esi; pop ebp; ret
parent @ 00406fc1: mov ebx,eax; call 004085e0
```

### ABI trap

Do **not** model as void/no-arg true cdecl with undefined EBX. **EBX is the formal.** Parent destroy always sets it from EAX.

### Role trap

Do not fold into destroy-bucket-table or tree free. This unit **only** drains chains to freelist; parent frees slab + `delete[]` table.

### Neighbor trap

`0x00408590` is tree iterator ++ (isnil@+0x31 family). Same page, different system.

---

## 4. Residual gaps (agreed with A)

1. Product English / demangle.
2. Typed payload dtor vs scalar delete.
3. Runtime / differential.

**Verdict:** **accept-with-gaps** — no CF reject; ABI/role/freelist sealed; product open.
