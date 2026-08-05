# Review B (skeptical / adversarial): `aa_005b43b0` StdList_AllocSentinel_0x30_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_005b43b0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (OWN-ONLY W35-G) |
| **Counterpart** | `reviews/A_aa_005b43b0_StdList_AllocSentinel_0x30_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | Function is truly `void` (Ghidra signature) | **Falsified** — 5 callers assign return (`uVar1 = FUN_005b43b0()`); body leaves EAX = node after `operator_new`; stores do not clobber EAX |
| 2 | This is a full list object ctor (head+size in one alloc) | **Falsified** — only 0x30 node; size is separate adjacent dword zeroed by callers |
| 3 | Same as Ass CircularSentinel 0x28 (`0x00423d60`) | **Falsified** — `push 0x30` not 0x28; NestedHash W34 reports document the split |
| 4 | Second store is gated on node non-null same as first | **Partially true / note** — second test is `node+4 != 0`, not `node != 0`; null path would store to `0x4` (relies on non-null new) |
| 5 | Node size is only next+prev (8 B) | **Falsified** — `push 0x30`; payload span present but uninitialized here |
| 6 | Classification "wrapper" means thunk to another list API | **Rejected as port guidance** — body is complete factory (new+link); wrapper_hint only flags return-type inheritance from `operator_new` |
| 7 | Dead / rare helper | **Falsified** — 5 live callers across NestedHash + Obj list + large host |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Empty circular sentinel role | **High** | Wrong container init |
| EAX return | **High** | Lost head pointer |
| 0x30 size / next+prev | **High** | Heap corruption |
| Family relation to 0xC/0x18 | **High** | Duplicate ports |
| Product English of payload | **Low** | Naming only |
| Runtime | **Open** | Matrix policy |

---

## 3. Cross-check against raw + bytes + callers

```
// Body hex @ 0x005b43b0 (26 B):
// 6A 30 | E8 .. | 83 C4 04 | 85 C0 74 02 89 00 | 8D 48 04 85 C9 74 02 89 01 | C3

// NestedHash_Ctor_Sentinel0x30 (0x00463bd0):
//   head = FUN_005b43b0();  this+8 = head; this+0xc = 0; fill 9 buckets
// NestedHashBag_Ctor_Sentinel0x30 (0x004438c0): same 0x30 sentinel pattern
// Obj_DefaultCtor (0x005b3f60): list@+0x10 head = FUN_005b43b0(); size = 0
// FUN_004d8a10: head = FUN_005b43b0(); adjacent size0
// Twin factories: 0x004933f0 (0xC), 0x00457c60 (0x18) — identical CF skeleton
```

Live decompile 2026-07-29 ≡ raw 2026-07-23 CF. Full-body hex seals return path.

---

## 4. Surviving contract for AutoCore

```
// Port as bare 0x30 sentinel factory:
void* StdList_AllocSentinel_0x30(void) {
  void* n = operator_new(0x30);
  if (n) *(void**)n = n;
  // retail: *(n+4) = n when (n+4)!=0
  return n;
}
// Pair with separate size=0 at call sites.
// Do NOT use Ass CircularSentinel_Alloc0x28 for NestedHash0x30 hosts.
// Ignore Ghidra void return.
```

---

## 5. Verdict

Adversarial pass confirms A on factory role/ABI/self-link/return/size. Residual product English + payload layout → **accept-with-gaps**.
