# Review B (skeptical / adversarial): `aa_00421b50` StdTree_Max_Isnil29_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00421b50` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-08-04` |
| **Counterpart** | `reviews/A_aa_00421b50_StdTree_Max_Isnil29_Inferred.md` |
| **Agent** | WQ9D-G OWN-ONLY dual |
| **Verdict** | **accept-with-gaps** on behavior/ABI; product name remains Inferred |

---

## 1. Claims under attack

| # | Claim | Attack result |
|---|---|---|
| 1 | Function is truly `void` | **Falsified** — callers store EAX into `head+8`; leave EAX is result |
| 2 | This is leftmost / min | **Falsified** — walks `node+8` (right); twin min walks `*node` (`FUN_0051b5d0`) |
| 3 | isnil is at `+0x19` (Val12) | **Falsified** — `CMP [reg+0x29],0` only |
| 4 | `__thiscall` / ECX node | **Falsified** — `mov eax,[esp+4]`; no ECX this |
| 5 | Decompiler while is bit-exact | **Falsified for empty-right** — bytes return **start**, decompiler would surface nil child |
| 6 | Skill-domain unique helper | **Falsified as sole role** — shared std map erase; skill maps are one consumer class |
| 7 | Product name is retail-known | **Unproven** — `_Inferred` |
| 8 | Runtime Confirmed | **Rejected** — no Launcher; Terminal false |
| 9 | Unlimited walk / no nil guard | **Falsified** — each step tests isnil before continuing |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| EAX node* return / cdecl | **Confirmed** | Wrong port ABI → head corruption |
| Right walk + isnil@0x29 | **Confirmed** | Wrong twin (min/max swap) |
| Empty-right returns start | **Confirmed** | Erase installs nil into head->right |
| “StdTree_Max” English | **High structural / Inferred product** | Rename only if demangle appears |
| Exact value_type size | Open | Layout of key/payload beyond isnil |

---

## 3. Cross-check

```
00421b50:  rightmost isnil29 — 28 B, cdecl, EAX
0051b5d0:  leftmost isnil29  — twin min (WQ9D-B)
00418bf0:  rightmost isnil19 — StdTree_Max_Val12
00409220:  erase: if head.right==erased → Max(repl) or parent
Map_ExactFindByIntKey: same isnil@0x29 family
```

**Attack on “decompiler void means no return value”:** five call sites assign the call result; body ends with result in EAX.

**Attack on “+0x29 is color not isnil”:** color is `+0x28` in same erase body (`param_3[10]`); isnil tests use `+0x29` consistently with find helpers.

---

## 4. Surviving contract for AutoCore

```
// Node partial:
//   +0 left, +4 parent, +8 right, +0x29 isnil

int32_t *StdTree_Max_Isnil29_Inferred(int32_t *node) {
  int32_t *r = (int32_t *)node[2];
  if (*(char *)((uintptr_t)r + 0x29)) return node;
  do { node = r; r = (int32_t *)node[2]; }
  while (!*(char *)((uintptr_t)r + 0x29));
  return node;
}
```

Port notes:
- Prefer bytes over Ghidra void/while.
- Pair with min twin for erase head link updates.
- Do not merge with Val12 (`isnil@+0x19`) helpers.

---

## 5. Gaps

1. Product demangle / map value_type English.  
2. Twin min dual owned elsewhere.  
3. Runtime / bit-exact / differential.

**Verdict:** **accept-with-gaps**.
