# Review B (skeptical / adversarial): `aa_00628f10` ActionHost_RemoveReverseListEntry_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00628f10` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (W24-P) |
| **Counterpart** | `reviews/A_aa_00628f10_ActionHost_RemoveReverseListEntry_Inferred.md` |
| **Verdict** | **accept-with-gaps** on sealed CF; reject listed false claims |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | `cdecl` / no this | Decomp of parent omitted this | **Falsified** — uses **ECX** for host fields; **`ret 4`** |
| 2 | ECX is manager (same as 0062a410) | Same unregister parent | **Falsified** — parent loads **`ECX=*(action+0x10)`** before call; different object |
| 3 | Swap-with-last O(1) remove | Common game pattern | **Falsified** — **shift-left** loop preserves order of remaining entries |
| 4 | Early-out if not found (no count change) | Safe API assumption | **Falsified** — **`count--` always** after search; miss sets index=-1 |
| 5 | Does not touch action fields | List-only | **Falsified** — **`mov dword [action+0x10], 0`** |
| 6 | No dirty / flag side effect | Pure unlink | **Falsified** — **`mov byte [host+0x28], 1`** |
| 7 | Product name sealed | String plate | **Fail** — none |
| 8 | Bit-exact / runtime verified | Static dual | **Fail** if claimed |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| thiscall host + ret 4 | **High** | Stack / wrong object |
| list +0x4c/+0x50 + shift | **High** | Corrupt reverse list |
| clear action+0x10 | **High** | Stale host link |
| dirty +0x28 | **High** | Missed rebuild |
| not-found path | **Med** | count underflow if mis-called |
| Product English | **Low–Med** | Doc only |

---

## 3. Cross-check against raw / bytes

```text
// decompiler:
find action in host+0x4c[0..count)
count--
shift if index < count
action+0x10 = 0
host+0x28 = 1

// bytes: ECX host; ret 4; same CF; MATCH
// parent residual was on CALL SITE this, not this unit's body.
```

**Attack on “swap-remove”:** **Fails** — multi-iter shift.
**Attack on “no side effects on action”:** **Fails** — clears +0x10.
**Attack on “safe miss”:** **Fails** — always decrements count.

---

## 4. Surviving contract for AutoCore

```
ActionHost_RemoveReverseListEntry(host, action):  // thiscall
  index = find action in host.list_at_0x4c[0..count_at_0x50)
  if not found: index = -1
  host.count_at_0x50 -= 1
  if index < host.count_at_0x50:
    shift-left entries from index
  action.back_host_at_0x10 = null
  host.dirty_at_0x28 = 1
```

**Port tests:**

* Host is **not** the action manager; it is `*(action+0x10)` on the primary unregister path.
* Preserve shift semantics (not swap-with-last).
* Always clear `action+0x10` and set dirty even when list was empty / miss (match retail).
* Do not invent an early return that skips count--.

---

## 5. Open questions

1. Product names for host / list owner.
2. Who consumes `host+0x28`.
3. Whether miss path is ever hit in live play.
4. Runtime / bit-exact.
