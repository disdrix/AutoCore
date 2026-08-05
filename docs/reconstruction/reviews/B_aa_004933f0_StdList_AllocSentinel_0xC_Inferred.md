# Review B (skeptical / adversarial): `aa_004933f0` StdList_AllocSentinel_0xC_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004933f0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (OWN-ONLY W32-P) |
| **Counterpart** | `reviews/A_aa_004933f0_StdList_AllocSentinel_0xC_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | Function is truly `void` (Ghidra signature) | **Falsified** — 20 callers assign return (`uVar1 = FUN_004933f0()`); body leaves EAX = node after `operator_new`; stores do not clobber EAX |
| 2 | This is a full list object ctor (head+size in one alloc) | **Falsified** — only 0xC node; size is separate adjacent dword zeroed by callers |
| 3 | Same as SEH factory `0x0040fb90` bit-for-bit | **Falsified** — `0x0040fb90` has SEH frame / larger body; link logic equivalent, prologue differs |
| 4 | Second store is gated on node non-null same as first | **Partially true / note** — second test is `node+4 != 0`, not `node != 0`; null path would store to `0x4` (relies on non-null new) |
| 5 | Node size is 8 (next+prev only) | **Falsified** — `push 0xC`; third dword present but uninitialized here |
| 6 | No real callers / dead code | **Falsified** — 28 xrefs / 20 named callers including PalantirEnv and NDSpecialFX |
| 7 | Classification "wrapper" means thunk to another list API | **Rejected as port guidance** — body is complete factory (new+link); wrapper_hint only flags return-type inheritance from `operator_new` |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Empty circular sentinel role | **High** | Wrong container init |
| EAX return | **High** | Lost head pointer |
| 0xC size / next+prev | **High** | Heap corruption |
| Family relation to 0040fb90 | **High** | Duplicate ports |
| Product English | **Low** | Naming only |
| Runtime | **Open** | Matrix policy |

---

## 3. Cross-check against raw + bytes + callers

```
// Body hex @ 0x004933f0 (26 B):
// 6A 0C | E8 .. | 83 C4 04 | 85 C0 74 02 89 00 | 8D 48 04 85 C9 74 02 89 01 | C3

// PalantirEnv_Ctor pattern (0x00492dd0):
//   head = FUN_004933f0();  slot = head;  size = 0;
// NDSpecialFX_Ctor: six identical head+size pairs.
// Twin SEH factory 0x0040fb90: same new(0xC)+self-link under LAB_009bc7d0.
```

Live decompile 2026-07-29 ≡ raw 2026-07-23 CF. Full-body hex seals return path.

---

## 4. Surviving contract for AutoCore

```
// Port as bare 0xC sentinel factory:
void* StdList_AllocSentinel_0xC(void) {
  void* n = operator_new(0xC);
  if (n) *(void**)n = n;
  // retail: *(n+4) = n when (n+4)!=0
  return n;
}
// Pair with separate size=0 at call sites.
// Do not merge with SEH twin 0x0040fb90 unless deliberately sharing.
// Ignore Ghidra void return.
```

---

## 5. Verdict

Adversarial pass confirms A on factory role/ABI/self-link/return. Residual product English + third-dword payload → **accept-with-gaps**.
