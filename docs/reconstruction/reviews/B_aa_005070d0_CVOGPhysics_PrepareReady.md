# Review B (skeptical / adversarial): `aa_005070d0` CVOGPhysics_PrepareReady

| Field | Value |
|---|---|
| **Stable ID** | `aa_005070d0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_005070d0_CVOGPhysics_PrepareReady.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | “Profiler / no-op stub” (suspImpulse notes) | Prior-art “optional profiler probes” wording | **Falsified** — real calls into list activate; `host+0x29` written **1** in `FUN_0055eb80` |
| 2 | Dirty-bit flip only on `phys` | Simple flag mental model | **Falsified** — flag is on **`*(phys+0x44)+0x29`**, not on phys header |
| 3 | Decompiler `FUN_0055e490(param_1)` / `FUN_0055eb80(iVar1)` is ABI-complete | Trust Ghidra arity | **Falsified as complete ABI** — both callees are **thiscall with `ECX=*(phys+8)`**; stack args are phys then host |
| 4 | Always activates host | Skip second gate | **Falsified** — needs `host+0x29==0` **and** `host+0x24!=-1` |
| 5 | Runs even when no world | Missing early-out | **Falsified** — `*(phys+8)==0` → immediate return (no callees) |
| 6 | Null-safe on `phys+0x44` | Defensive port | **Falsified** — no host null test; `cmp [eax+0x29]` faults if host null |
| 7 | Writes rigid body / vtbl on `phys+0x3c` | Bundle with SetAngVel/ApplyImpulse | **Falsified** — zero body access; pure host/world bookkeeping |
| 8 | Same as probe `FUN_005070b0` | Address off-by confusions | **Falsified** — probe is read-only `ret 4`; prepare is write-side activate |
| 9 | `FUN_0055eb80(host)` as thiscall on host | Decompiler one-arg form | **Falsified** — `this=world`, stack=`host` (prologue `mov edi,ecx` + `[esp+…]` host) |
| 10 | Name `PrepareReady` is string-proven | Symbol inflation | **Not sealed** — **Probable** from probe/prepare pairing; Ghidra still `FUN_005070d0` |
| 11 | `FUN_0055e490` is “always remove and destroy phys” | Over-read callee | **Not sealed as hot path** — only acts if phys found in `world+0x108` list; often no-op (**Probable**) |
| 12 | Single caller (TeleportTarget alias) | Named-callee scaffold | **Falsified** — **≥64** xrefs across vehicle, network, AI, reactions |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Own-body CF + immediates `+8`, `+0x44`, `+0x29`, `+0x24`, `-1` | **High** | Wrong gate → double-activate or skip |
| Callee ABI (`ECX=world`, stack phys/host) | **High** | Port passes wrong `this` → heap corruption |
| Ready flag location `host+0x29` set by activate | **High** | Probe/prepare desync |
| Early out on null world | **High** | Spurious prepare on unbound phys |
| No body/`+0x3c` involvement | **High** | Invented physics writes |
| `FUN_0055e490` English role | **Medium** | Doc only; CF possible remove+refcount |
| Type names world/host | **Low–Med** | Naming only |
| Full 64-site role map | **Medium** | Miss exotic call pattern (none seen) |

---

## 3. Cross-check against raw + asm

```text
// raw aa_005070d0 decompiler shape (under-stated ABI):
if (*(param_1+8) != 0) {
  FUN_0055e490(param_1);                 // ACTUAL: thiscall world, arg phys
  host = *(param_1+0x44);
  if (*(char*)(host+0x29)==0 && *(int*)(host+0x24)!=-1)
    FUN_0055eb80(host);                  // ACTUAL: thiscall world, arg host
}

// sealed asm contract:
world = *(phys+8)
if world==0: return
FUN_0055e490(world, phys)
host = *(phys+0x44)                      // unchecked
if host.ready==0 && host.index!=-1:
  FUN_0055eb80(world, host)              // sets host.ready=1
```

Raw body control **keywords** match; **argument binding must follow asm**, not the one-arg decompiler forms.

---

## 4. Surviving contract for AutoCore

```
CVOGPhysics_PrepareReady(phys):
  world = phys.field_08
  if world == null:
      return
  // optional world-side bookkeeping on phys (often no-op)
  World_MaybeRemoveFromPendingList(world, phys)   // FUN_0055e490

  host = phys.field_44                    // NO null check here
  if host.ready_byte_29 != 0:
      return
  if host.index_24 == -1:
      return
  World_ActivateHost(world, host)         // FUN_0055eb80
  // side effect: host.ready_byte_29 = 1
  // (+ list insert, index rewrite, FUN_0062a6c0, clear +0x30/+0x34/+0x38)

// Standard caller pairing:
ready = CVOGPhysics_ProbeReady(phys, &b)  // FUN_005070b0
if ready==0 && phys.field_44 != null:
    CVOGPhysics_PrepareReady(phys)
// then body vtbl write…
```

**Port tests that matter:**

* Must **not** treat this as empty profiler no-op.
* Must pass **world** as callee `this`, not phys/host.
* Must preserve gates: null world; ready already set; index `== -1`.
* Must **not** add a silent null-host return if retail would fault (or document intentional harden).
* Probe/prepare pairing: ready flag is **`host+0x29`**, set only on activate path.

---

## 5. Open questions

1. Type recovery for `phys+8` / `phys+0x44` (RTTI / ctor duals).
2. When `host+0x24 == -1` — never-pooled host? destroyed slot?
3. Hit rate of `FUN_0055e490` list match on vehicle hot path.
4. Whether any caller invokes prepare **without** the probe pre-check (direct call sites exist — verify host non-null invariant).

**Verdict:** **accept-with-gaps** — adversarial attacks on profiler-no-op, decompiler ABI, and single-caller naming **fail**; remaining gaps are type names and deep callee duals only.
