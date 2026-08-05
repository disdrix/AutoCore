# Function record: WeatherHost_ApplyEnvTime_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_005575c0` |
| **Canonical name** | `WeatherHost_ApplyEnvTime_Inferred` (**Inferred** structural) |
| **Ghidra name** | `FUN_005575c0` |
| **Address** | `0x005575c0`–`0x005579be` exclusive (**1022 B**) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | client weather / env-time transition + nfx preload |
| **Completion status** | **Dual-reviewed** W36-F — **accept-with-gaps** |
| **Bit-for-bit / runtime / diff** | Open (deferred) |

## Purpose

Drive weather host env-time slot application: weather lookup (with forgotten-weather default seed), nfx list fill then activate via sealed helper, cooperative AssPreloader key-ring steps with yield/enqueue, 5000 ms transition blend, prev/cur swap, apply.

## Signature

```c
// __thiscall; RET 0x4
void WeatherHost_ApplyEnvTime_Inferred(void* host /*ECX*/, uint8_t env_time_slot);
```

| Formal | Source | Conf |
|---|---|---|
| host | ECX (`MOV ESI,ECX`) | **High** |
| env_time_slot | stack +4; cleaned by RET 4 | **High** |
| return | void | **High** |

## Host layout (use-sites)

| Off | Role |
|---|---|
| `+0x174` | current key |
| `+0x178` | enable gate |
| `+0x17c` / `+0x180` | cur / prev weather* |
| `+0x188` | apply helper arg |
| `+0x18c` | tick base |
| `+0x190` / `+0x1a4` | nfx fill / activate GuardedVector rings |
| `+0x1b8` | cached slot |
| `+0x1bc` / `+0x1bd` | fill / act ready flags |
| `+0x1c0` | ring cursor |

## Callers / callees

| Direction | Targets |
|---|---|
| Callers | `FUN_005579c0` (sole parent, 2 call sites) |
| Callees | W32-I nfx helper; W35-A ProcessKeyRingStep; W32-K ExpandDeps; weather lookup/seed/apply helpers |

## Artifacts

| Kind | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_005575c0_FUN_005575c0.md` |
| Annotated | `docs/reconstruction/raw/aa_005575c0_FUN_005575c0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/WeatherHost_ApplyEnvTime_Inferred.cpp` |
| Twin | `docs/reconstruction/reconstructed-exact/FUN_005575c0.cpp` |
| Review A/B | `docs/reconstruction/reviews/A_aa_005575c0_WeatherHost_ApplyEnvTime_Inferred.md`, `B_…` |
