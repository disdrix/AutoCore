# Review B (skeptical / adversarial): `aa_00419b80` CNDHash_BucketUnlinkByU64Key

| Field | Value |
|---|---|
| **Stable ID** | `aa_00419b80` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_00419b80_CNDHash_BucketUnlinkByU64Key.md` |
| **Verdict** | **accept** on CF/ABI/offsets; product English name remains **Probable** only |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | Decompiler `if (param_1 != 0)` means “non-zero keyLo” | Bytes load ECX from keyLo **slot after find**; find wrote pred there | **Falsified** — predecessor test |
| 2 | This function frees the node / dtors value | No `delete`, no vtbl call, no freelist write | **Falsified** — parent `00413a60` owns that |
| 3 | Unlinks ordered list `+0x20/+0x24` | Only `+0x10` / header `+4` touched | **Falsified** |
| 4 | `__cdecl` / thiscall ECX=hash | `ret 8`; EBX header; no ECX use as this | **Falsified** — stdcall keys + EBX bucket |
| 5 | Skip integrity on miss | `jz` lands on `mov edi,ebx; call ad0` | **Falsified** — always ad0 |
| 6 | Head store runs on miss | Miss jumps past `mov [ebx+4],eax` | **Falsified as bug** — sealed correct |
| 7 | Same as u32 `CNDHash_LookupByKey` unlink | Different node layout / ABI | **Falsified** mix-up |
| 8 | Name is PDB `CNDHash_BucketUnlinkByU64Key` | No PDB string | **Not sealed** — Probable |
| 9 | Runtime verified | Static only | **Open** |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| `ret 8` + stack key dwords | **Confirmed** | Stack smash |
| EBX header / head@+4 / next@+0x10 | **Confirmed** | Corrupt wrong bucket |
| predOut keyLo-slot reuse | **Confirmed** | Port testing keyLo as pred → always mid-splice wrong |
| Return node not value | **Confirmed** | Parent reads `node+0xc` after |
| Always ad0 | **Confirmed** | Miss skips repair if port omits |
| English name | **Medium** | Docs only |
| All callers set EBX correctly | **Medium** | Assumed from remove dual + two xrefs |

---

## 3. Cross-check against raw / bytes

```text
// raw decompile fiction:
iVar1 = FUN_00419b40(param_1, param_2);
if (iVar1) {
  if (param_1) { *(param_1+0x10) = *(iVar1+0x10); ad0(); return iVar1; }
  *(EBX+4) = *(iVar1+0x10);
}
ad0(); return iVar1;

// machine correction:
// param_1 at "if" is *predOut (keyLo slot), EBX is bucket
```

Hex (full body):  
`8b4424088b4c2404565750518d7c24148bc3e8a9ffffff8bf085f6741f8b4c240c85c98b461074118bfb894110e81effffff5f8bc65ec208008943048bfbe80dffffff5f8bc65ec20800`

Sibling find (`aa_00419b40`) seals key@`+0x18/+0x1c`, next@`+0x10`, head@header`+4` — geometry matches.

Parent remove (`aa_00413a60`) seals this as **bucket** step only; list/freelist follow in parent.

---

## 4. Surviving contract for AutoCore

```
CNDHash_BucketUnlinkByU64Key (custom ABI):
  in  EBX = bucketHeader*
  stk keyLo, keyHi   // stdcall, ret 8
  out EAX = Node* or NULL  // unlinked from bucket chain only

  // NOT a full hash remove
  // NOT value lookup (use 00413b30 / find+0xc)
  // Parent must still: transfer value, unlink ordered list, freelist push
```

**Port tests:**

* Head match → head becomes node->next; return old head; ad0 runs.
* Mid match → pred->next bypasses node; return node; ad0 runs.
* Miss → EAX==0; head unchanged; ad0 still runs.
* After unlink, node->next still points at old successor (not cleared here).

---

## 5. Open questions

1. Exact product symbol vs macro in original source.
2. Whether `FUN_004197b0` passes the same EBX/bucket convention without hash-table lock edge cases.
3. Interaction if ad0 cuts a cycle mid-chain that included the just-unlinked node (node already spliced out — should be fine).

**Verdict:** **accept** — adversarial checks strengthen machine ABI/CF; do not trust decompiler `param_1` as key at the pred branch.
