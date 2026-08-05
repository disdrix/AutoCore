# Review B (skeptical / adversarial): `aa_00423b10` NDResource_GetDefaultTypeToken_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00423b10` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (W18-D) |
| **Counterpart** | `reviews/A_aa_00423b10_NDResource_GetDefaultTypeToken_Inferred.md` |
| **Verdict** | **accept** |

**Tools:** Ghidra `decompile_function` + `read_memory` only.

---

## 1. Claims under attack

| # | Claim | Result |
|---|---|---|
| 1 | Returns the vtable pointer `0x00a95ae8` | **Falsified** — returns **`0x00d1f734`** (object address) |
| 2 | Re-inits every call | **Falsified** — once-flag bit 0 skips body |
| 3 | Thread-safe C++11 magic static | **Unproven / unlikely** — plain flag `or`, no locks (classic MSVC CRT once) |
| 4 | Allocates heap type object | **Falsified** — static storage `DAT_00d1f734` only |
| 5 | Type token is a formal of LoadByKey | **Falsified in parent** — inserted from this return, not caller arg |
| 6 | Name is PDB product symbol | **Unproven** — **Inferred** from parent NDResource dual |
| 7 | atexit not present / optimized out | **Falsified** — push `009c3070` + call + `add esp,4` |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Singleton address return | **High** | Cache type mismatch / always-miss |
| Once flag semantics | **High** | Double atexit / torn vptr |
| Role as LoadByKey type arg | **High** | Wrong cache namespace |
| Product class name | **Low / open** | Docs only |

---

## 3. Cross-check against raw + bytes

```
B8 01 00 00 00          mov eax,1
84 05 38 F7 D1 00       test [d1f738], al
75 1D                   jnz ready
09 05 38 F7 D1 00       or  [d1f738], eax
68 70 30 9C 00          push LAB_009c3070
C7 05 34 F7 D1 00 E8 5A A9 00 00   mov [d1f734], a95ae8
E8 …                    call atexit
83 C4 04                add esp,4
B8 34 F7 D1 00          mov eax, d1f734
C3                      ret
```

Decompiler reorders store-before-atexit vs push-before-store; single-threaded init equivalent.

---

## 4. Surviving contract for AutoCore

```c
// Port: process-wide default resource type token
static std::atomic_flag once; // or plain int if matching CRT races is required
static TypeToken g_defaultType;

TypeToken* NDResource_GetDefaultTypeToken() {
  static bool init = false;
  if (!init) {
    init = true;
    g_defaultType.setVtable(/* PTR_FUN_00a95ae8 methods */);
    // atexit optional in server port if no CRT teardown needed
  }
  return &g_defaultType;
}
// LoadByKey must pass this pointer as the type key into the cache.
```

---

## 5. Open questions

1. Product name of the type class.
2. Whether server needs atexit teardown parity.
3. Other type-token singletons for non-default resource kinds.

**Verdict:** **accept**
