# Review B (skeptical / adversarial): `aa_005a2410` TNL_NetClassRepInstance_Ctor

| Field | Value |
|---|---|
| **Stable ID** | `aa_005a2410` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (W21-K) |
| **Counterpart** | `reviews/A_aa_005a2410_TNL_NetClassRepInstance_Ctor.md` |
| **Verdict** | **accept** |

**Tools:** Ghidra `decompile_function` + `read_memory` only (no `disassemble_bytes`).

---

## 1. Claims under attack

| # | Claim | Result |
|---|---|---|
| 1 | This is a free/delete destructor | **Falsified** — no free of object; installs vtbl, strdup, list insert; `ret 0x10` |
| 2 | `__cdecl` / stack-only this | **Falsified** — `mov esi,ecx` before body; thiscall |
| 3 | Stack arg order is version,type,group,name (reversed) | **Falsified** — CRT pushes version first (RTL) so name is first stack arg; decompile param_2=name |
| 4 | Group/type/version store slots swapped | **Falsified** — bytes: `[esi+4]=group`, `[esi+8]=version`, `[esi+0xC]=type` matches decompile |
| 5 | Does not link ClassList (only sets local field) | **Falsified** — writes `DAT_00d179a4 = esi` after reading prior head into `+0x34` |
| 6 | Name stored without heap copy (pointer only) | **Falsified** — `_strdup` IAT call; result → `+0x20` |
| 7 | Invented product name without evidence | **Falsified as risk** — RTTI `NetClassRepInstance` + CRT string + TNL.NET ctor shape; name is **High**, not pure invention |
| 8 | Body is the only ClassRep ctor in the image | **Not claimed** — many siblings write same list head; this VA is one entry point |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| ABI thiscall + 4 args | **High** | Wrong port calling convention |
| Field offsets 4/8/C/20/34 | **High** | Corrupt ClassRep layout in server port |
| ClassList prepend | **High** | Missing classes in Create/lookup |
| Role = NetClassRepInstance ctor | **High** | Mis-tier naming only (CF still sealed) |
| Exhaustive multi-template coverage | **Low** (scope) | Other ctors not this unit |

---

## 3. Cross-check against raw + bytes

```
base_init(this);
*this = NetClassRepInstance_vtbl;
this->name = strdup(className);
this->version = classVersion;
this->type = classType;
this->groupMask = classGroupMask;
this->classId[0..3] = 0;
this->next = ClassListHead;
ClassListHead = this;
return this;
```

Clean must **not** invent Create-factory body, CRC init, or ClassTable sort (`NetClassRep.Initialize` is separate).

---

## 4. Surviving contract for AutoCore

```c
// Port of TNL_NetClassRepInstance_Ctor
// Register static ClassRep instances at process init (or equivalent).
struct NetClassRepInstance {
  void* vtbl;
  uint32_t classGroupMask; // +0x04
  uint32_t classVersion;   // +0x08
  uint32_t classType;      // +0x0C
  uint32_t classId[4];     // +0x10
  char* className;         // +0x20  (owned heap string)
  // ... base fields ...
  NetClassRepInstance* next; // +0x34
};

// Dtor sibling frees className; do not leak.
// ClassList is a global singly linked list via next.
```

Align with existing `TNL.NET` `NetClassRep` / `NetClassRepInstance` rather than inventing a second registry.

---

## 5. Open questions

1. Whether every retail ClassRep uses this exact entry vs sibling ctors.
2. Live values of base counters after `FUN_0042aea0` in running process.
3. Bit-exact ClassRep memory dump vs TNL.NET managed layout — deferred.

**Verdict:** **accept**
