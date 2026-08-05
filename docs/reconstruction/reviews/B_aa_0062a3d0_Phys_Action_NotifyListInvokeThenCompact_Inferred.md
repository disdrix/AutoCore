# Review B (skeptical / adversarial): `aa_0062a3d0` Phys_Action_NotifyListInvokeThenCompact_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0062a3d0` |
| **Canonical name** | `Phys_Action_NotifyListInvokeThenCompact_Inferred` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_0062a3d0_Phys_Action_NotifyListInvokeThenCompact_Inferred.md` |
| **System** | `physics` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | Args are `(world, action)` as parent dual text | Trust Ghidra parent order | **Falsified** — MSVC push world then action ⇒ formals **`(action, world)`**; body uses first formal for `+0x3c` |
| 2 | Array lives on world at `+0x3c` | Symmetric with host lists | **Falsified** — first formal is **action** (EDI at site) |
| 3 | thiscall on world | Match sibling helpers | **Falsified** — **cdecl** `ADD ESP,8`; no ECX setup at call site |
| 4 | Forward iterate 0..n-1 | | **Falsified** — reverse `count-1 … 0` |
| 5 | Calls applyAction `vtbl+0x14` | RegisterAction confusion | **Falsified** — **`vtbl+0x8`** only |
| 6 | Frees the array | | **Falsified** — densify nulls via `005fff20`; no allocator free here |
| 7 | Multiple callers | | **Falsified** — sole xref RegisterAction |
| 8 | Product name sealed | | **Holds open** |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| cdecl `(action, world)` | **Confirmed** | Wrong notify target / crash |
| Reverse walk + null skip | **Confirmed** | Missed notify / double free if inverted |
| vtbl+8(world) | **Confirmed** | Wrong lifecycle hook |
| Tail compact `005fff20` | **Confirmed** | Leaked null holes / stale count |
| List English / element type | **Open** | Port semantics |
| Product name | **Low** | Doc |

---

## 3. Cross-check against raw / live

```text
raw decomp: walk param_1+0x3c reverse; vcall +8(param_2); FUN_005fff20()
live asm:   EDI=arg0=action; count=[action+0x40]; header action+0x3c;
            EBX=arg1=world; call [vtbl+8]; mov eax,header; jmp 005fff20
site:       PUSH EBP(world); PUSH EDI(action); CALL; ADD ESP,8
```

Parent dual B previously wrote `FUN_0062a3d0(world, action)` — **arg order doc bug**; CF role (post-register notify) still holds.

### Sentinel / sibling traps

| Trap | B position |
|---|---|
| Merge with HostActionList push | **Reject** |
| Merge with pair push | **Reject** |
| Treat as applyAction registration | **Reject** — that is `006292a0` + later integrate |
| Assume destroys list elements | **Reject** — only invokes + compacts nulls |

---

## 4. Surviving contract for AutoCore

```
Phys_Action_NotifyListInvokeThenCompact(action, world):  // cdecl
  for i = action.listCount(+0x40)-1 downto 0:
    p = action.listData(+0x3c)[i]
    if p != null:
      p.vtbl[+0x8](world)     // thiscall-like on p
  CompactNulls(action.listHeader @ +0x3c)   // FUN_005fff20
```

**Port tests:**

* Called exactly once at end of RegisterAction after host loop.
* Must not use `vtbl+0x14` here.
* Null entries after notify are removed so count matches live pointers.

---

## 5. CF challenge of Review A

| A claim | B position |
|---|---|
| Corrects parent arg order | **Agree Confirmed** |
| thiscall-like vcall on element | **Agree High** — stack has world; ECX=element |
| Compact removes nulls only | **Agree** |
| Name `_Inferred` | **Agree** open |

---

## 6. Open questions

1. What fills `action+0x3c` (collect vtbl+0x18 vs other)?
2. Element class / vtbl+8 English.
3. Whether reverse order matters for multi-listener side effects.

**Verdict:** **accept-with-gaps** — leaf sealed; parent residual for this VA closed.
