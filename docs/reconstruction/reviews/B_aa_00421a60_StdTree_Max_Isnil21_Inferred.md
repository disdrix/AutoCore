# Review B (skeptical / adversarial): `aa_00421a60` StdTree_Max_Isnil21_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00421a60` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-08-05` |
| **Counterpart** | `reviews/A_aa_00421a60_StdTree_Max_Isnil21_Inferred.md` |
| **Agent** | R13-001 OWN-ONLY dual |
| **Verdict** | **accept-with-gaps** on behavior/ABI; product name remains Inferred |

---

## 1. Claims under attack

| # | Claim | Attack result |
|---|---|---|
| 1 | Function is truly `void` | **Falsified** — callers store EAX into `head+8`; leave EAX is result |
| 2 | This is leftmost / min | **Falsified** — walks `node+8` (right); twin min walks left (`FUN_004cb2c0`) |
| 3 | isnil is at `+0x29` (isnil29 Max) | **Falsified** — `CMP [reg+0x21],0` only; peer Max isnil29 is `0x00421b50` |
| 4 | isnil is at `+0x19` (Val12) | **Falsified** — `+0x21` only |
| 5 | `__thiscall` / ECX node | **Falsified** — `mov eax,[esp+4]`; call-site `ADD ESP,4` |
| 6 | Decompiler while is bit-exact | **Falsified for empty-right** — bytes return **start**, decompiler would surface nil child |
| 7 | Skill-domain unique helper | **Falsified as sole role** — shared std map erase; skill maps are one consumer class |
| 8 | Product name is retail-known | **Unproven** — `_Inferred` |
| 9 | Runtime Confirmed | **Rejected** — no Launcher; Terminal false |
| 10 | Unlimited walk / no nil guard | **Falsified** — each step tests isnil before continuing |
| 11 | Same body as isnil29 Max | **Falsified** — identical plate shape, different isnil imm (`0x21` vs `0x29`) |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| EAX node* return / cdecl | **Confirmed** | Wrong port ABI → head corruption |
| Right walk + isnil@0x21 | **Confirmed** | Wrong twin (min/max or family merge) |
| Empty-right returns start | **Confirmed** | Erase installs nil into head->right |
| “StdTree_Max” English | **High structural / Inferred product** | Rename only if demangle appears |
| Exact value_type size | Open | Layout of key/payload beyond isnil |

---

## 3. Cross-check

```
00421a60:  rightmost isnil21 — 28 B, cdecl, EAX   [OWN R13-001]
004cb2c0:  leftmost  isnil21 — twin min           [residual R13-002]
00421b50:  rightmost isnil29 — StdTree_Max_Isnil29_Inferred
00418bf0:  rightmost isnil19 — StdTree_Max_Val12
004043e0:  rightmost isnil31 — StdTree_Max_Isnil31
00405650:  erase: if head.right==erased → Max(repl) or parent  [R12-009 parent]
```

**Attack on “decompiler void means no return value”:** seven call sites assign the call result (`MOV [EBX+8],EAX` after `ADD ESP,4`); body ends with result in EAX.

**Attack on “+0x21 is color not isnil”:** color is `+0x20` in same erase body family; isnil tests use `+0x21` consistently with isnil21 erase/insert/rotate peers (`00405650`, `00407200`, `0050e9f0`, `005a27f0`).

**Attack on “merge with isnil29 Max at 00421b50”:** bytes differ only in isnil imm (`21` vs `29`); wrong merge corrupts head extremity for wrong node size family.

---

## 4. Surviving contract for AutoCore

```
// Node partial (isnil21 / 0x28):
//   +0 left, +4 parent, +8 right, +0x20 color, +0x21 isnil

int32_t *StdTree_Max_Isnil21_Inferred(int32_t *node) {
  int32_t *r = (int32_t *)node[2];
  if (*(char *)((uintptr_t)r + 0x21)) return node;
  do { node = r; r = (int32_t *)node[2]; }
  while (!*(char *)((uintptr_t)r + 0x21));
  return node;
}
```

Port notes:
- Prefer bytes over Ghidra void/while.
- Pair with min twin `004cb2c0` for erase head link updates.
- Do not merge with Val12 (`isnil@+0x19`), isnil29 (`+0x29`), or isnil31 Max helpers.

---

## 5. Gaps

1. Product demangle / map value_type English.  
2. Twin min dual owned elsewhere (R13-002).  
3. Runtime / bit-exact / differential.

**Verdict:** **accept-with-gaps**.
