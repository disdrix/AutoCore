# Review B (skeptical / adversarial): `aa_0062a410` ActionManager_NotifyListenersAndCompact_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0062a410` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (W24-P) |
| **Counterpart** | `reviews/A_aa_0062a410_ActionManager_NotifyListenersAndCompact_Inferred.md` |
| **Verdict** | **accept-with-gaps** on sealed CF; reject listed false claims |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | `__thiscall` ECX=manager | Assume parent pattern | **Falsified** — parent pushes ECX then ESI; this unit loads manager from **[esp+4]**; no ECX use as this |
| 2 | `__stdcall` / `ret 8` | Stack cleanup by callee | **Falsified** — **no ret**; tail JMP; parent **`ADD ESP, 8`** → **cdecl** |
| 3 | `FUN_005fff20()` has no input | Trust decompiler | **Falsified** — bytes **`MOV EAX, EDI`** (manager+0x3c) before JMP; `005fff20` uses **in_EAX** |
| 4 | Forward walk 0..count-1 | Natural loop | **Falsified** — **reverse** `count-1 … 0` (`sub`/`jns`) |
| 5 | Calls vtbl[0] / Release | COM assumption | **Falsified** — call is **`[vtbl+0xC]`** (slot 3) |
| 6 | This is list-remove of action | Confuse with 00628f10 | **Falsified** — only notifies listeners + compact; no touch of action+0x10 |
| 7 | Product name sealed by string | Plate hunt | **Fail** — no body strings |
| 8 | Bit-exact / runtime verified | Static dual only | **Fail** if claimed |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Notify reverse walk + null skip | **High** | Missed listener / wrong order |
| cdecl + tail compact | **High** | Stack imbalance / wrong compact target |
| table at +0x3c/+0x40 | **High** | Wrong manager field |
| vtbl+0xC thiscall | **High** | Wrong virtual |
| Product English | **Low–Med** | Doc only |
| What compact assumes (nulls inserted by vfunc?) | **Med** | Incomplete lifecycle story |

---

## 3. Cross-check against raw / bytes

```text
// decompiler:
for i = count-1; i >= 0; --i:
  p = *(base + i)
  if p: (*p->vtbl+0xC)(action)
FUN_005fff20();   // residual: missing EAX=manager+0x3c

// bytes: edi=manager; esi=count; edi+=0x3c; reverse loop; call [vtbl+0xC];
//        eax=edi; jmp 005fff20
// MATCH on CF; decomp residual on compact this only.
```

**Attack on “thiscall manager”:** **Fails** — stack arg0.
**Attack on “stdcall ret 8”:** **Fails** — tail + parent cleans.
**Attack on “removes action from list”:** **Fails** — peer is `00628f10`.

---

## 4. Surviving contract for AutoCore

```
ActionManager_NotifyListenersAndCompact(manager, action):
  vec = manager + 0x3c   // {base*, count@+4}
  for i from vec.count-1 down to 0:
    listener = vec.base[i]
    if listener != null:
      listener.vtbl[3](listener, action)   // +0xC
  FUN_005fff20 with EAX = vec   // compact nulls
// cdecl; caller cleans 8
```

**Port tests:**

* Do not use ECX as manager this.
* Preserve reverse notify order.
* After notify, compact the **same** +0x3c vector (not +0x48 sibling).
* Caller must `ADD ESP, 8` (or equivalent).

---

## 5. Open questions

1. Product names for manager / listener.
2. Dual of `FUN_005fff20`.
3. Whether listener vfuncs intentionally null themselves before compact.
4. Runtime / bit-exact.
