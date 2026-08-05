# Review B (skeptical / adversarial): `aa_00419b40` CNDHash_BucketFindNodeByU64Key

| Field | Value |
|---|---|
| **Stable ID** | `aa_00419b40` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_00419b40_CNDHash_BucketFindNodeByU64Key.md` |
| **Verdict** | **accept** on CF/ABI/offsets; product English name remains **Probable** only |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | Decompiler `void` means no return | Body leaves EAX=node; caller `00413b30` uses EAX as node | **Falsified** — returns `Node*` in EAX |
| 2 | Same layout as `CNDHash_LookupByKey` (`005b0920`) | u32 key@+0x10, value@+0x08, thiscall ECX | **Falsified** — this unit is u64 @+0x18/+0x1c, next@+0x10, custom EAX/EDI |
| 3 | Returns value payload | No load of +0xc in body | **Falsified** — returns node; `00413b30` loads +0xc |
| 4 | `__cdecl` / thiscall | `ret 8` + stack keyLo/keyHi after two pushes | **Falsified** — **stdcall** 8 bytes; header/pred in registers |
| 5 | `in_EAX`/`unaff_EDI` are decompiler bugs to ignore | Insert dual documents EDI freelist/hash context; body uses both | **Falsified as bugs** — intentional custom ABI |
| 6 | PredOut only set on match | `*EDI=node` only on **advance** path; match jumps over store | **Survives as sealed** — pred = true predecessor (0 if head match) |
| 7 | Empty chain leaves predOut garbage | `mov [edi],0` before empty check | **Falsified** — always zeroed first |
| 8 | Compare is OR-match (either dword) | `jne` after lo; only if lo equal does hi cmp; both must equal | **Falsified** — AND match |
| 9 | Name is PDB `CNDHash_BucketFindNodeByU64Key` | No PDB string in unit | **Not sealed** — Probable inference only |
| 10 | Runtime / bit-exact verified | Static only | **Open** |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| `ret 8` + stack key dwords | **Confirmed** | Wrong CC → stack smash on return |
| EAX header / EDI predOut | **Confirmed** | Unlink splices wrong node |
| Offsets +0x04 / +0x10 / +0x18 / +0x1c | **Confirmed** | Miss all keys / infinite wrong chain |
| Return node not value | **Confirmed** | Callers treating EAX as payload → type confuse |
| vs `005b0920` layout mix-up | **High** | Port wrong node stride → silent corruption |
| English name | **Medium** | Docs only |
| All call sites set EDI writable | **Medium** | Assumed from family pattern; one bad site crashes |

---

## 3. Cross-check against raw / bytes

```text
// raw decompile (register fiction kept):
iVar1 = *(int *)(in_EAX + 4);
*unaff_EDI = 0;
for (; (iVar1 != 0 && ((param_1 != *(int *)(iVar1 + 0x18)
        || (param_2 != *(int *)(iVar1 + 0x1c)))));
     iVar1 = *(int *)(iVar1 + 0x10)) {
  *unaff_EDI = iVar1;
}
// machine adds: return iVar1 in EAX; ret 8
```

Hex (full body):  
`8b400485c0c707000000007423538b5c240c568b74240c8b48183bf18b501c75043bda740989078b401085c075e95e5bc20800`

Sibling insert (`aa_00413920`) seals node key assignment at +0x18/+0x1c and bucket head-insert at header+4 — same geometry.

---

## 4. Surviving contract for AutoCore

```
CNDHash_BucketFindNodeByU64Key (custom ABI):
  in  EAX = bucketHeader*
  in  EDI = Node** predOut
  stk keyLo, keyHi   // stdcall, ret 8
  out EAX = Node* or NULL
  *predOut = 0 initially;
             predecessor of match, or last node on miss, or 0 if empty/head-match

// NOT CNDHash_LookupByKey (u32 / thiscall / returns value)
// NOT a full-table scan — single bucket chain only; caller selects bucket
```

**Port tests:**

* Head match → return head, `*predOut == 0`.
* Second-node match → `*predOut == first`, return second.
* Miss on non-empty → EAX==0, `*predOut == last`.
* Empty → EAX==0, `*predOut == 0`.
* keyLo match + keyHi mismatch → continue walk (not early success).

---

## 5. Open questions

1. Whether freelist-tombstone nodes (value@+0xc == 0) should still "match" — **yes they do** at this layer; insert soft/dup checks inspect +0xc after return.
2. Exact product symbol of helper vs inlined macro in original source.
3. `FUN_00419620` / `007fe5b0` / `00800af0` / `00800c30` call-site audits (out of OWN scope).

**Verdict:** **accept** — adversarial checks strengthen machine ABI/CF; do not conflate with u32 `CNDHash_LookupByKey`.
