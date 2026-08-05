# Review A (reconstruction fidelity): `aa_004f1e20` Clonebase_EnsureDefLoaded_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004f1e20` |
| **VA** | `0x004f1e20` |
| **Canonical name** | `Clonebase_EnsureDefLoaded_Inferred` |
| **Prior names** | `FUN_004f1e20`, `Named_VOG_DEBUG_STOP_004f1e20` |
| **Review date** | `2026-07-29` (OWN-ONLY dual A/B) |
| **Reviewer role** | Independent reconstruction review (raw ≡ live ≡ entry bytes) |
| **Counterpart** | `reviews/B_aa_004f1e20_Clonebase_EnsureDefLoaded_Inferred.md` |
| **System** | `inventory-transfer` / item def load (shared clonebase) |
| **Dual status** | **Present** (first dual seal) |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

**Thread-safe ensure-load** for a **clonebase / cloned-object-base** (`this` in ECX):

```text
int __thiscall Clonebase_EnsureDefLoaded_Inferred(
    Clonebase* this,   // ECX
    char doPhyReload,  // stack param_2  (often 0 from store/UI paths)
    char doNameLoad)   // stack param_3  (often 1 from store/UI paths)
{
    EnterCriticalSection(this + 0x10);

    if (*(char*)(this + 0x29) == 0) {          // not yet "loaded once"
        if (*(void**)(this + 0x3c) != 0)
            (*(vtbl)**(this+0x3c))(1);         // release prior def object

        err = FUN_0059c000(this);              // primary def/materialize
        if (err != 0) {
            FUN_007a4480(0, "VOG_DEBUG_STOP");
            LeaveCriticalSection(this+0x10);
            return err;
        }

        // Optional name / NFX path when doNameLoad and def has wide name @ def+0x316:
        if (doNameLoad && def_ok && wcslen(def+0x316) > 1) {
            if (doPhyReload) {
                // new(8) + FUN_004a1620 → this[+0x88]
                // FUN_00402d50(def+0x316) → FUN_004a6390 (nfx attach)
            }
            snprintf(buf, 0x104, "%S%s", def+0x316, "_nfx.xml");  // DAT_009ca184
            // FUN_0043d650/670 + FUN_00404ba0 load path
        }
        *(char*)(this + 0x29) = 1;             // mark loaded
    }

    if (doPhyReload)
        FUN_004f1c70();                        // Phy_Preload_ReloadRigidBody (sibling dual)

    *(int*)(this + 0x30) += 1;                 // refcount / use count
    LeaveCriticalSection(this + 0x10);
    return 0;
}
```

**Common call shape from store predicates** (`Item_IsWantedByStore`, `Item_GetStoreSellPrice`):

```text
// ECX = *(item + 0xA8)  // clonebase
// push 1; push 0; call  →  (doPhyReload=0, doNameLoad=1)
```

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw | `docs/reconstruction/raw/aa_004f1e20_FUN_004f1e20.md` |
| Annotated | `docs/reconstruction/raw/aa_004f1e20_FUN_004f1e20.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/FUN_004f1e20.cpp` |
| Function record | `docs/reconstruction/functions/aa_004f1e20_FUN_004f1e20.md` |
| Live decompile | Ghidra `0x004f1e20` ≡ raw |
| Live entry | `read_memory` `0x004f1e20` — SEH, `mov esi,ecx`, `lea ebp,[esi+0x10]`, `EnterCriticalSection` |
| Suffix string | `read_memory` `0x009ca184` → `"_nfx.xml"` |
| Call-site store | `get_assembly_context` `0x00513783` / `0x005142b3`: `push 1; push 0; call` with ECX=clonebase |
| Sibling | `Phy_Preload_ReloadRigidBody` `aa_004f1c70` |
| Consumers | store want `aa_00513770`, sell price `aa_005142a0`, GiveItemByCbid, tooltip, many equip paths |

**Not performed:** `disassemble_bytes`, full dual of `FUN_0059c000`, Launcher.

---

## 3. ABI (SEALED)

| Slot | Role | Evidence |
|------|------|----------|
| ECX `this` | clonebase* | entry `mov esi,ecx`; store callers `mov ecx,[item+0xa8]` |
| stack `param_2` | doPhyReload / nfx-create gate | `push 0` then `push 1` → second push is first stack arg |
| stack `param_3` | doNameLoad (`_nfx.xml` path) | first push = last arg |
| return | `0` success; non-zero = `FUN_0059c000` error (debug stop path) | raw |

MSVC thiscall push order (right-to-left):

```text
push param_3   ; 1 = doNameLoad
push param_2   ; 0 = doPhyReload
call ; ECX=this
```

---

## 4. Clonebase offsets (this)

| Offset | Role | Conf |
|-------:|------|------|
| `+0x10` | CRITICAL_SECTION | **High** |
| `+0x29` | loaded-once flag (char) | **High** |
| `+0x30` | use/refcount (int, ++) | **High** |
| `+0x3c` | def* (item definition blob) | **High** (family duals) |
| `+0x88` | optional nfx/object handle when phy path | **Probable** |
| def `+0x316` | wide name / resource stem | **High** (wcslen + snprintf) |

---

## 5. Control flow: clean ≡ raw ≡ live

| Stage | Match |
|---|---|
| Enter CS at `this+0x10` | **Yes** |
| Skip heavy path if `+0x29 != 0` | **Yes** |
| Release prior def via vtbl(1) | **Yes** |
| `FUN_0059c000` load; fail → VOG_DEBUG_STOP + return err | **Yes** |
| Name path gated by param_3 + name length | **Yes** |
| Phy/nfx create gated by param_2 inside name path | **Yes** |
| Always-on param_2 → `FUN_004f1c70` after flag set | **Yes** |
| `+0x30++` then Leave CS; return 0 | **Yes** |

---

## 6. Confidence

| Claim | Confidence |
|---|---|
| thiscall clonebase ensure-load | **High** |
| Store args `(0,1)` = no phy reload, yes name load | **High** |
| CS / loaded flag / def at `+0x3c` | **High** |
| `_nfx.xml` suffix | **Confirmed** |
| English of `FUN_0059c000` / nfx callees | **Probable / Open** |
| Product symbol | **Open** (`_Inferred`) |
| Runtime | **Open** |

---

## 7. Gaps

1. Full dual of primary loader `FUN_0059c000`.
2. Exact product type of `this` (CVOGClonedObjectBase vs sibling).
3. Why some callers pass `(1,1)` (GiveItem / equip) vs `(0,1)` (store) — phy path side effects.
4. Sentinel check `def != -0x316` is pointer-arithmetic null guard for `def+0x316`.

**Verdict:** **accept-with-gaps**
