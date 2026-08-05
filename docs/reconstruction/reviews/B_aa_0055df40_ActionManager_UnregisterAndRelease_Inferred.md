# Review B (skeptical / adversarial): `aa_0055df40` ActionManager_UnregisterAndRelease_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0055df40` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (W23-P) |
| **Counterpart** | `reviews/A_aa_0055df40_ActionManager_UnregisterAndRelease_Inferred.md` |
| **Verdict** | **accept-with-gaps** on sealed CF; reject listed false claims |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | This is only a COM Release | Assume single refdec | **Falsified** — always runs notify (`0062a410`) + list remove (`00628f10`) before refdec |
| 2 | `__cdecl` / no stack cleanup | Ghidra void signature noise | **Falsified** — **`ret 4`**, one stack arg |
| 3 | Decomp `FUN_00628f10(action)` is complete ABI | Trust decompiler | **Falsified** — bytes load **ECX=`*(action+0x10)`** before call |
| 4 | Does not touch `action+0xC` | Only refcount | **Falsified** — `mov dword [esi+0xC], 0` always |
| 5 | Named_CalleeOf_SERVER_GOT_GIGO is product name | Scaffold alias | **Not sealed** — parent-seed noise only |
| 6 | Callers need not re-release | Assume this is sole Release | **Falsified** — `004f7d60` / peers often decrement short@+6 **again** after return |
| 7 | Manager is the vehicle entity | ECX = entity | **Falsified** — destroy path loads **`*(world+0xe4a4)`** into ECX |
| 8 | Bit-exact / runtime verified | Static dual only | **Fail** if claimed |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Notify → remove → clear → release order | **High** | Wrong teardown order / use-after-free |
| ABI thiscall + ret 4 | **High** | Stack imbalance |
| reverse host via `action+0x10` | **High** | Wrong list unlink |
| short@+6 COM pattern | **High** | Leak or double-free with caller re-release |
| Product English | **Low–Med** | Doc only |
| Nested listener vtbl+0xC contract | **Med** (nested decomp only) | Incomplete port of notify |

---

## 3. Cross-check against raw / bytes

```text
// decompiler:
FUN_0062a410(param_1, param_2);
FUN_00628f10(param_2);          // residual: missing this=*(param_2+0x10)
*(short*)(param_2+6) -= 1;
param_2[3] = 0;                 // +0xC
if (refcount==0) (*vtbl)(1);

// bytes: push ecx/esi → 0062a410; mov ecx,[esi+10]; push esi → 00628f10;
//        add word[esi+6],-1; mov [esi+0xC],0; conditional call [vtbl]; ret 4
// MATCH on CF; decomp residual on 00628f10 this only.
```

**Attack on “this is pure Release without unregister”:** **Fails** — two side-effecting callees always run first.

**Attack on “SERVER_GOT_GIGO product API”:** **Fails** — no string evidence; structural unregister/release only.

---

## 4. Surviving contract for AutoCore

```
ActionManager_UnregisterAndRelease(manager, action):
  notify_listeners(manager, action)           // FUN_0062a410
  host = action.back_host_at_0x10
  list_remove(host, action)                   // FUN_00628f10; nulls action+0x10
  action.registered_at_0xC = 0
  action.refcount_i16_at_6 -= 1
  if action.refcount_i16_at_6 == 0:
    action.vtbl[0](action, 1)
```

**Port tests:**

* Always clear `+0xC` even when refcount remains > 0.
* Reverse unlink uses host from `action+0x10`, not manager.
* Callers may perform an extra short release after return — do not invent ownership that absorbs both.
* Manager identity is not the vehicle entity; world slot `+0xe4a4` is the common source.

---

## 5. Open questions

1. Product names for manager / action / listener interfaces.  
2. Dual of `FUN_0062a410` / `FUN_00628f10`.  
3. Why some callers double-release after this unit (holder ownership accounting).  
4. Runtime / bit-exact.
